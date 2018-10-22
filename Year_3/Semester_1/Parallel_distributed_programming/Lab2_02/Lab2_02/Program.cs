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
        static int rows = 16;
        static int columns = 16;
        static int[] temp = new int[rows * columns];
        static int[,] matrixA = new int[rows, columns];

        static int[,] matrixB = new int[rows, columns];
        static int[,] result = new int[rows, columns];
        static Thread[] threadPool;

        static void RunAddition(Tuple<int, int> indexes)
        {
            for (int index = indexes.Item1; index <= indexes.Item2; index++)
            {
                for (int i = 0; i < rows; i++)
                {
                   result[index, i] = matrixA[index, i] + matrixB[index, i];
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
            int nrThreads = 1;
            threadPool = new Thread[nrThreads];

            int i = 0, j = 0;
            int rowsPerThread;
            if (rows >= nrThreads)
            {
                rowsPerThread = rows / nrThreads - 1;
            }
            else
            {
                rowsPerThread = 0;
            }

            while (i < rows && j < nrThreads)
            {
                var index = i;
                Tuple<int, int> indexes = new Tuple<int, int>(index, index + rowsPerThread);
                threadPool[j] = new Thread(() => RunAddition(indexes));
                threadPool[j].Start();
                i += 1 + rowsPerThread; j++;
            }

            for (i = 0; i < nrThreads; i++)
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

            //PrintMatrix(result);
            Console.WriteLine("Elapsed={0}", sw.ElapsedMilliseconds);
            Console.ReadKey();
        }
    }
}