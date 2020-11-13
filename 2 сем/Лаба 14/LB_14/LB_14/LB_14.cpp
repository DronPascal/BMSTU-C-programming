// LB_14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

void razn_to_center(int **arr, int n, int j);

void main()
{
	int n,m,i,j,S=0,Sbuf=0;
	setlocale(0, "russian");
	srand (time(NULL));
	do{
		printf("Введите размер матрицы, число строк должно быть нечетным: ");
		scanf("%d %d", &n, &m);
	}while (n % 2==0);

	int **arr=new int*[n];
	for (j=0; j<n; j++)
	{
		arr[j]= new int[m];
	}
	//заполнение
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			arr[i][j]=rand()%101-50;
		}
	}

	
	//вывод
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n\n", arr[i][j]);
	}
	//преобразование
	for (j=0; j<m; j++)
	{
		razn_to_center(arr, n, j);
	}
	//вывод 2
	printf("\n\n	Вывод №2\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n\n");
	}

	for (i=0; i<n; i++) {delete [] arr[i];};
	delete [] arr;
	
	getch();	
}

void razn_to_center(int **arr, int n, int j)
{
	int pluss=0, minus=0;
	for (int i=0; i<n; i++)
	{
		if (arr[i][j] > 0) pluss++;
		else if (arr[i][j] < 0) minus++;
	}
	printf("В %d-м стольбце %d положительных и %d отрицательных элементов. Разница: %d\n", j+1, pluss, minus, pluss-minus);
	arr[n/2][j]=pluss-minus;
}