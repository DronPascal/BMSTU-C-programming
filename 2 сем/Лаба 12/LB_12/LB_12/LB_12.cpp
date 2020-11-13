// LB_12.cpp : Defines the entry point for the console application.
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
		printf("Введите четные размеры матрицы: ");
		scanf("%d %d", &n, &m);
	}while ((n % 2 == 1) || (m % 2 == 1));

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

	int *razn=new int[n/2];

	for (j=0; j<m; j++)
	{
		Sbuf+=arr[0][j];
	}

	for (i=1; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
				S+=arr[i][j];
		}
		if ((i+1)%2==0){razn[(i+1)/2-1]=S-Sbuf;}
		Sbuf=S;
		S=0;
	}
	
	//вывод
	for (i=0; i<m; i++) printf("     ");
	printf("		Сумма чисел строки");
	printf("	Разность сумм\n");
	for (i=0; i<n; i++)
	{
		S=0;
		for (j=0; j<m; j++)
		{
			S+=arr[i][j];
			printf("%5d", arr[i][j]);
		}
		printf("%		%5d", S);
		printf("\n\n");
		if ((i+1)%2==1)
		{
		for (int s=0; s<m; s++) {printf("     ");}
		printf("					%d", razn[(i+1)/2]);
		}
		printf("\n\n");
	}

	printf("\nМассив разностей:\n");
	for (i=0; i<n/2; i++)
	{
		printf("		 %d) %p => %d\n",i+1, razn+i, razn[i]);
	}

	for (i=0; i<n; i++) {delete [] arr[i];};
	delete [] arr;

	getch();	
}