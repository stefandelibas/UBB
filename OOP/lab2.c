#include <stdlib.h>
//#include <stdafx.h>
#include <stdio.h>

typedef struct
{
	int arr[100];
	int length;
} vector;

/*
Prints the available menu for the problem
Input: -
Output: the menu is printed at the console
*/
void printMenu()
{
	printf("1 - to read a number n.\n");
	printf("2 - to compute the n pairs of twin numbers \n");
	printf("3 - to compute the longest decreasing contiguous subsequence \n");
	printf("4 - first n prime numbers \n");
	printf("0 - to exit.\n");
}
/*
Reads an integer number from the keyboard. Asks for number while read errors encoutered.
Input: the message to be displayed when asking the user for input.
Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
/*
check if the command is a valid number(available in the menu list)
input: a number which represents the command
output: 1 - if the command is valid
		0 - if the command is not valid
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 4)
		return 1;
	return 0;
}

/*
check if an integer number is prime
input: a  - an integer number
output: 1 - if a is prime
		0 - if a is not prime
*/
int is_prime(int a)
{
    int d;
	if (a % 2 == 0 && a != 2 || a <= 1)
		return 0;
	for (d = 3; d*d <= a; d++)
		if (a%d == 0)
			return 0;
	return 1;
}

/*
Reads a vector of integer numbers.
Output: v - of type vector, the read vector.
*/
vector readVector(int* n)
{
	vector v;
	int i = 0;
	v.length = *n;
	for (i = 0; i < v.length; i++)
	{
		v.arr[i] = readIntegerNumber("new element=");
	}

	return v;
}
// Prints the elements of a vector between the given positions (start and end).
void printVector(vector v, int start, int end)
{
	int i = 0;
	for (i = start; i <= end; i++)
	{
		printf("%d ", v.arr[i]);
	}
	printf("\n");
}
/*
computes the longest decresing contiguous subsequence in an array
input:	v - a vector
output:	start - the  starting point of the subsequence
		end - the ending point
*/
void getLongestDecresingContiguousSubSequence(vector v, int* start, int* end)
{
	*start = 0;
	*end = 0;
	int max_difference = 0;
	int i,cnt = 1,j = 0,k = 0;
	for (i = 1; i < v.length; i++)
	{
		if (v.arr[i] < v.arr[i - 1])
			cnt++;
		else
		{
			j = i;
			cnt = 1;
		}
		if (cnt > k)
		{
			k = cnt;
			*start = j;
			*end = i;
		}
	}
}
int main()
{
	/*
	11.
	a.
	Determine the first n pairs of twin numbers, where n is a given natural and non-null number.
	Two prime numbers p and q are called twin if q–p = 2.
	b.
	Given a vector of numbers, find the longest decreasing contiguous subsequence.
	*/
	int n;
	int command = -1;
	int ok = 0;
	while (1)
	{
		printMenu();
		command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;

		switch (command)
		{
			case 1:
			{
				printf("n=");
				scanf("%d", &n);
				ok = 1;
				break;
			}
			case 2:
			{
				if (ok == 0)
				{
					printf("You have to assign an integer number to n before calling this case.");
					break;
				}
				int i = 1, k = 2;
				while (i <= n)
				{
					if (is_prime(k) && is_prime(k + 2))
					{
						printf("%d - %d \n", k, k + 2);
						i++;
					}
					k += 1;
				}
				break;
			}
			case 3:
			{
				if (ok == 0)
				{
					printf("You have to assign an integer number to n before calling this case.");
					break;
				}
				vector v = readVector(&n);
				printf("The longest decreasing contiguous subsequence is:\n");
				int start = 0, end = 0;
				getLongestDecresingContiguousSubSequence(v, &start, &end);
				printVector(v, start, end);
				break;
			}
			case 4:
			{
				if (ok == 0)
				{
					printf("You have to assign an integer number to n before calling this case.");
					break;
				}
				int i = 1, k = 2;
				while (i <= n)
				{
					if (is_prime(k))
					{
						printf("%d \n", k);
						i++;
					}
					k++;
				}
				break;
			}
		}
	}



    return 0;
}

