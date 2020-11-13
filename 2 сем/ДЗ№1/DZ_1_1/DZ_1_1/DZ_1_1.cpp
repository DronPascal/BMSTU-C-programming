// DZ_1_1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

void delete_column (int **arr, int n, int k, int *cur_cul);

void main()
{
	int n,i,j,cur_col;
	setlocale(0, "russian");
	srand (time(NULL));
	do{
		printf("Введите размер квадратной матрицы: ");
		scanf("%d", &n);
		cur_col=n;
	}while (n < 1);

	int **arr=new int*[n];
	for (j=0; j<n; j++)
	{
		*(arr+j)= new int[n];
	}
	//заполнение
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			*(*(arr+i)+j)=rand()%100;
		}
	}

	//вывод изначальной матрицы
	printf("\n	Вывод №1 (изначальная)\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%4d", *(*(arr+i)+j));
		}
		printf("\n\n", *(*(arr+i)+j));
	}
	//преобразование
	printf("\nЭлементы на диагонали, кратные трем: ");
	for (i=n-1; i>=0; i--)
	{
		if (*(*(arr+i)+i) % 3 == 0)
		{			
			printf("%d (%d-й столбец)   ", *(*(arr+i)+i), i+1);
			delete_column(arr, n,  i, &cur_col);
		}
	}
	
	printf("\n\n	Вывод №2 (с удаленными столбцами)\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<cur_col; j++)
		{
			printf("%4d", *(*(arr+i)+j));
		}
		printf("\n\n", *(*(arr+i)+j));
	}

	for (i=0; i<n; i++) {delete [] arr[i];};
	delete [] arr;
	
	getch();	
}

void delete_column (int **arr, int n, int k, int *cur_col) //удаляет столбец и уменьшает текущее кол-во столбцов
{
	if (k==n-1)
	{
		for (int i=0; i<n; i++) 
			*(*(arr+i)+n-1)=0;
	}
	else
	{
		for (int i=0; i<n; i++)
			for (int j=k; j<n-1; j++)
				*(*(arr+i)+j)=*(*(arr+i)+j+1);
	}
	*cur_col-=1;
} 