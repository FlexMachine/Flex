// LAb1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
//Test for Lab PO 
int factorial(int);
void initialization_array2D(int**arr, int rows, int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			*(*(arr + i) + j) = factorial(j + i);
		}
	}
}
int factorial(int x)
{
	if (x < 0)
		return 0;
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}
void print_array2D(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}
int* array1D(int** arr, int SIZE, int N, int M)
{
	int size = M * (N / 2);

	int* arr1D = new int[size];
	int index = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; j++)
			arr1D[index++] = arr[i][j];

	return arr1D;
}
void print_array1D(int* arr1, int size)
{
	cout << endl << endl;

	for (int i = 0; i < size;i++)
	{
		cout << arr1[i] << '\t';

	}
}
int main()
{
	const int rows = 5;
	const int cols = 5;

	int** array2 = new int*[rows];
	for (int i = 0; i < rows;i++)
	{
		*(array2 + i) = new int[cols];
	
	}
	initialization_array2D(array2, rows, cols);
	
	print_array2D(array2, rows, cols);
	const unsigned int size = 25;
	int* array_1 = array1D(array2, size, rows, cols);
	print_array1D(array_1, size);
	cin.get();
	return 0;
}

