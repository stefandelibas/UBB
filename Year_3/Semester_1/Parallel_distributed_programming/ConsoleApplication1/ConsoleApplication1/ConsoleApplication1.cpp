#include "stdafx.h"

#include <future>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <string>/*
#include "boost\asio\thread_pool.hpp"
#include "boost/asio.hpp"
#include "boost\bind.hpp"*/

static const int rows = 160;
static const int columns = 160;
int matrixA[rows][columns];
int matrixB[rows][columns];
int result[rows][columns];

void FillMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixA[i][j] = 1;
			matrixB[i][j] = 2;
		}
	}
}
void RunMultiplication(int index)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[index][i] += matrixA[index][j] * matrixB[j][i];
		}
	}

}

void MultiplyMatricesFuture()
{
	std::future<void> futures[rows];
	for (int i = 0; i < rows; i++)
	{
		futures[i] = std::async(std::launch::async, RunMultiplication, i);
	}
}

//void MultiplyMatricesThreadPool()
//{
//	boost::asio::thread_pool pool(rows);
//
//	for (int i = 0; i < rows; i++)
//	{
//		boost::asio::post(pool, [i]()
//		{
//			RunMultiplication(i);
//		});
//	}
//	pool.join();
//}

void PrintMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
}
int main()
{
	FillMatrix();
	clock_t begin = clock();

	MultiplyMatricesFuture();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "time elapsed:" << elapsed_secs << "\n";
	//PrintMatrix();

	int x;
	std::cin >> x;
	return 0;
}