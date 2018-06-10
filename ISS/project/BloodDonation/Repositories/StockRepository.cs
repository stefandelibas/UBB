using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BloodDonation.repositories
{
    class StockRepository : IRepository<Stock>
    {
        public void Add(Stock element)
        {
            /*
             * Adds a stock entry into the DataBase in the "Stocks" table
             * Input: element = the stock entry that needs to be added
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Stocks.Add(element);
                context.SaveChanges();
            }
        }

        public void Delete(Stock element)
        {
            /*
             * Deletes a stock entry from the DataBase located in the "Stocks" table
             * Input: element = the stock entry that needs to be deleted
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                context.Stocks.Remove(element);
                context.SaveChanges();
            }
        }

        public List<Stock> GetElements()
        {
            /*
             * Selects all stock entries from the DataBase located in the "Stocks" table
             * Input: none
             * Output: a list of stock entries
             */
            List<Stock> list;
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                list = context.Stocks.ToList();
            }
            /*Note: Am pus return-ul aici deoarece nu eram sigur ca destructorul de la context apuca sa mai 
             * fie apelat daca puneam return-ul in block-ul using !*/
            return list;
        }

        public void Update(Stock element)
        {
            /*
             * Updates a person from the DataBase located in the "Stocks" table
             * Input: element = the stock entry with the updated info that needs to replace the old entry
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                Stock entry = context.Stocks.FirstOrDefault(e => e.idDonation == element.idDonation);
                this.Delete(entry);
                this.Add(element);
            }
        }

        public void Refresh()
        {
            /*
             * Refreshes the stock by deleting the expired ones
             * Input: none
             * Output: none
             */
            using (Blood_DonationEntities context = new Blood_DonationEntities())
            {
                DateTime localDate = DateTime.Now;//today's date
                //get all expired stocks in a list
                List<Stock> expiredStocks = context.Stocks.Where(stock => stock.expirationDate < localDate).ToList();
                //remove all expired stocks from database
                expiredStocks.ForEach(stock => context.Stocks.Remove(stock));
            }
        }
    }
}
