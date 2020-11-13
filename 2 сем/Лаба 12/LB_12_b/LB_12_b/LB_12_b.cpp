// LB_12_b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

void main()
{
	int n,m,i,j,S=0,Sbuf=0;
	setlocale(0, "russian");
	srand (time(NULL));
	do{
		printf("Введите размер матрицы (max 10x10): ");
		scanf("%d %d", &n, &m);
	}while ((n > 10) || (m > 10));

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
			arr[i][j]=rand()%100;
		}
	}

	
	//вывод
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n\n", arr[i][j]);
	}
	printf("	Вывод №2\n\n");
	for (j=0; j<m; j++)
	{
		for (i=0; i<n; i+=2)
		{
			printf("%5d", arr[i][j]);
		}
		printf("	");
		if (j<n/2)
		for (int q=0; q<m; q++)
		{
			printf("%5d", arr[(j+1)*2-1][q]);
		}
		
		printf("\n\n");
	}

	for (i=0; i<n; i++) {delete [] arr[i];};
	delete [] arr;
	
	getch();	
}