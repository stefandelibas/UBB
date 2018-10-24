using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Lab3_Task_01
{

    class Program
    {
        static int rows = 1600;
        static int columns = 1600;
        static int[] temp = new int[rows * columns];
        static int[,] matrixA = new int[rows, columns];

        static int[,] matrixB = new int[rows, columns];
        static int[,] result = new int[rows, columns];

        static void RunMultiplication(Tuple<int, int> indexes)
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
            Task[] tasks = new Task[rows];
            for (int i = 0; i < rows; i++)
            {
                var multiplicacion = new Task((parameter) =>
                {
                    int index = (int)parameter;
                    Tuple<int, int> indexes = new Tuple<int, int>(index, index);
                    RunMultiplication(indexes);
                    
                },i);
                tasks[i] = multiplicacion;
                multiplicacion.Start();
            }
            Task.WaitAll(tasks);
                        
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
