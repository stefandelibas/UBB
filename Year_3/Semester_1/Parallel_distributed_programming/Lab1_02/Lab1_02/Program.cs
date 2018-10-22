using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab1_02
{
    class Program
    {
        public static int NR_INPUT_PRODUCTS_STOCK = 500;
        public static int NR_INPUT_PRODUCTS_BILL = 5;
        public static int MAX_SALES_PER_THREAD = 100000;
        public static int NR_THREADS = 8;
        public static int INITIAL_STOCK = 100000000;
        public readonly static Dictionary<int, Product> ProductsType = new Dictionary<int, Product>()
        {
            {0,new Product("A",3.5)},
            {1,new Product("B",4.8)},
            {2,new Product("C",3.8)},
            {3,new Product("D",3.5)},
            {4,new Product("E",4.8)},
            {5,new Product("F",3.8)},
            {6,new Product("G",3.5)},
            {7,new Product("H",4.8)}
        };

        class Quantity
        {
            public double quantity;
            public Quantity(double val)
            {
                this.quantity = val;
                
            }
            public override string ToString()
            {
                return this.quantity.ToString();
            }
        }
        class Shop
        {
            private object BillCRTID = 1;
            public SortedDictionary<Product, Quantity> products;
            public List<Bill> bills;
            public static double income;
            public int failedChecks = 0;

            public Shop()
            {
                income = 0d;
                bills = new List<Bill>();
                products = new SortedDictionary<Product, Quantity>();
                GenerateProducts();
                foreach (KeyValuePair<Product, Quantity> product in products)
                {
                    //Console.Write(product.Key + " " + product.Value + "\n");
                }
                //Console.WriteLine("--------------------------------------");

            }

            public int GetNextID()
            {
                //lock (BillCRTID)
                {
                    int crt = (int.Parse(BillCRTID.ToString()));
                    crt++;
                    BillCRTID = crt;
                    if (crt % 10 == 0)
                    {
                        //CheckConsitency();
                    }
                    return crt;
                }
            }

            private void GenerateProducts()
            {
                var random = new Random();

                for (int i = 0; i < ProductsType.Count ; i++)
                {
                    products.Add(ProductsType[i], new Quantity(INITIAL_STOCK));
                    //this.products[ProductsType[i]].quantity = 1000;
                }

                //for random generator of products:
                //x = random.Next(1, NR_INPUT_PRODUCTS_STOCK);
                //int x = NR_INPUT_PRODUCTS_STOCK;

                //for (int i = 0; i < x; i++)
                //{
                //    int idx = random.Next(0, ProductsType.Count());
                //    //int randomQuantity = random.Next(1, 5);
                //    int randomQuantity = 1;

                //    Product product = ProductsType[i % ProductsType.Count];

                //    if (products.ContainsKey(product))
                //    {
                //        products[product] += randomQuantity;
                //    }
                //    else
                //    {
                //        products.Add(product, randomQuantity);
                //    }
                //}
            }

            public void GenerateSales()
            {
                var random = new Random();
                //int noSales = random.Next(2, MAX_SALES_PER_THREAD);
                int noSales = MAX_SALES_PER_THREAD / NR_THREADS;
                Bill bill;

                Thread.Sleep(noSales / 10);
                for (int i = 0; i < noSales; i++)
                {
                    //create a new bill
                    int id = GetNextID();
                    lock (bills)
                    {
                        bill = new Bill(id);
                        bills.Add(bill);
                        
                        bill.GenerateProducts(products, BillCRTID);
                    }


                    if (bill.products.Count != 0)
                    {
                        //Console.WriteLine("\t done by thread " + Thread.CurrentThread.ManagedThreadId);
                        //Console.WriteLine();
                    }
                }
            }
            public void CheckConsitency()
            {

                //Console.WriteLine("performing check");
                lock (products)
                { 
                    double billIncome = 0d;
                    //Console.WriteLine("all resources locked");
                    foreach (var bill in bills)
                    {
                        billIncome += bill.billCost;
                    }
                    if (Math.Abs(income - billIncome) > 0.0001)
                    {
                        //Console.WriteLine("you messed up the bills.. income:" + income + " VS bill income:" + billIncome);
                        failedChecks++;
                    }
                    else
                    {
                        //Console.WriteLine("clean check ./");
                    }
                }
            }
            
        }

        public class Product : IComparable
        {
            public String name;
            public double price;

            public Product(string name, double price)
            {
                this.name = name;
                this.price = price;
            }

            public int CompareTo(object obj)
            {
                Product product = (Product)obj;
                return product.name.CompareTo(name);
            }
            public override string ToString()
            {
                return name;
            }

        }
        class Bill
        {
            public int id;
            public SortedDictionary<Product, int> products;
            public double billCost;

            public Bill(int id)
            {
                this.id = id;
                this.products = new SortedDictionary<Product, int>();
            }

            

            public void GenerateProducts(SortedDictionary<Product, Quantity> stockproducts,object BillCRTID)
            {
                var random = new Random();
                int x = 1;
                for (int i = 0; i < x; i++)
                {
                    
                    //int idx = random.Next(1, ProductsType.Count());
                    int randomQuantity = random.Next(1, NR_INPUT_PRODUCTS_BILL);
                    Product product = ProductsType[Thread.CurrentThread.ManagedThreadId % ProductsType.Count];
                    
                    lock (stockproducts[product])
                    {
                        if (stockproducts[product].quantity - randomQuantity > 0)
                        {
                            products.Add(product, randomQuantity);

                            stockproducts[product].quantity -= randomQuantity;
                            Shop.income += randomQuantity * product.price;
                            billCost += randomQuantity * product.price;

                           // Console.WriteLine("\t" + randomQuantity + " " + product.ToString() + "s");
                        }

                    }
                }
                if (products.Count != 0)
                {
                    //Console.WriteLine("Bill id:" + id);
                }
            }

            public override string ToString()
            {
                string str = "";
                str += "\n--------------------\n";
                str += "bill no:" + this.id + "\nProducts:";
                foreach (KeyValuePair<Product, int> product in this.products)
                {
                    str += product.ToString() + " ";
                }
                str += "\n--------------------\n";
                return str;
            }

        }

        static void Main(string[] args)
        {
            Shop shop = new Shop();
            List<Thread> threads = new List<Thread>();
            for (int i = 0; i < NR_THREADS; i++)
            {
                Thread T = new Thread(new ThreadStart(shop.GenerateSales));
                threads.Add(T);
            }
            Stopwatch sw = new Stopwatch();
            sw.Start();
            threads.ForEach(t => t.Start());

            threads.ForEach(t => t.Join());
            sw.Stop();

            

            shop.CheckConsitency();

            Console.WriteLine("------------------------------------------");
            Console.WriteLine("final stock:");
            foreach (KeyValuePair<Product, Quantity> product in shop.products)
            {
                Console.WriteLine(product.Key + " " + product.Value);
            }
            Console.WriteLine("FINAL INCOME=" + Shop.income);
            Console.WriteLine("failed checks:" + shop.failedChecks);

            Console.WriteLine("nr bills:" + shop.bills.Count);
            Console.WriteLine("Elapsed={0}", sw.ElapsedMilliseconds);
            Console.ReadKey();
        }
    }
}