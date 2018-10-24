using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab2_01
{

    class Program
    {
        static int nrThreads = 1;
        static int rows = 4;
        static int columns = 4;
        static int[] temp = new int[rows * columns];
        static int[,] matrixA = new int[rows, columns];
       
        static int[,] matrixB = new int[rows, columns];
        static int[,] result = new int[rows, columns];
        static List<Thread> threadPool;

        static void RunMultiplication(Tuple<int,int> indexes)
        {
            for (int index = indexes.Item1; index <= indexes.Item2; index++)
            {
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        result[index, i] += matrixA[index, j] * matrixB[j, i];
                    }
                }
            }
        }

        static void FillMatrix()
        {
            /* 
            matrixA[0, 0] = 1;
            matrixA[0, 1] = 2;
            matrixA[0, 2] = 3;
            matrixA[1, 0] = 6;
            matrixA[1, 1] = -1;
            matrixA[1, 2] = 4;
            matrixA[2, 0] = 5;
            matrixA[2, 1] = 1;
            matrixA[2, 2] = 3;

            matrixB[0, 0] = -4;
            matrixB[0, 1] = 2;
            matrixB[0, 2] = 3;
            matrixB[1, 0] = 2;
            matrixB[1, 1] = 2;
            matrixB[1, 2] = -3;
            matrixB[2, 0] = 1;
            matrixB[2, 1] = 5;
            matrixB[2, 2] = 1;
            */
            
            for (int i = 0; i < matrixA.GetLength(0); i++)
            {
                for (int j = 0; j < matrixA.GetLength(1); j++)
                {
                    matrixA[i, j] = 1;
                    matrixB[i, j] = 2;
                }
            }
            
        }

        static void MultiplyMatrices()
        {
           
            threadPool = new List<Thread>();
            
            int rowsPerThread;
            if (rows >= nrThreads)
            {
                rowsPerThread = rows / nrThreads - 1;
            }
            else
            {
                rowsPerThread = 0;
            }

            for(int i = 0; i < rows; i += 1 + rowsPerThread)
            {
                var index = i;
                Tuple<int,int> indexes = new Tuple<int, int> (index,index + rowsPerThread);
                threadPool.Add(new Thread(() => RunMultiplication(indexes)));
            }
            threadPool.ForEach(t => t.Start());

            for (int i = 0; i < nrThreads; i++)
            {
                try
                {
                    threadPool[i].Join();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }

        static void PrintMatrix(int[,] matrix)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write(string.Format("{0}    ", matrix[i, j]));
                }
                Console.Write(Environment.NewLine + Environment.NewLine);
            }
        }

        static void Main(String[] args)
        {
            FillMatrix();
            Stopwatch sw = new Stopwatch();
            sw.Start();
            MultiplyMatrices();
            sw.Stop();
            
            PrintMatrix(result);
            Console.WriteLine("Elapsed={0}", sw.ElapsedMilliseconds);
            Console.ReadKey();
        }
    }
}