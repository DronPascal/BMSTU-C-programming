// Z2_2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>


using namespace std;

void main()
{
	int i, j, n, m, u, p, *b;
	char **mstr, *ptr;
	srand (time(NULL));
	setlocale(0, "russian");
	
	puts("Введите размер символьной матрицы n x m (n<=8, m<=12)\n");
	do
	{
	scanf("%d %d",&n, &m);
	} while ((n>8) || (n<1) || (m>12) || (m<1));
	//вектор В(m) 
	b = new int[m];
	//символьная матрица размером A(n,m)
	mstr = new char * [n];
	for (i=0; i<m; i++)
	{
		mstr[i] = new char[m];
	}
	//заполнение и вывод A(n,m)
	for (i=0; i<n; i++)
	{
		ptr = mstr[i];
		for (j=0; j<m; j++)
		{
			*mstr[i]=(char)(rand()%11+32);
			printf("%5c", *mstr[i]);
			mstr[i]++;
		}
		mstr[i]=ptr;  
		puts("\n");
	}

	for (j=0; j<m; j++)
	{
		u=0; p=0; //обнуляем кол-во пробелов и знаков умножения
		for (i=0; i<n; i++)
		{
			ptr = mstr[i];
			mstr[i]+=j;
			if (*mstr[i]=='*')
			{
				u++;
			}
			else
			{
				if (*mstr[i]==' ')
				{
					p++;
				}
			}
			mstr[i]=ptr;
		}
		if (u>=p)
		{
			b[j]=1;
		}
		else
		{
			b[j]=0;
		}
	}

	puts("\nВектор В(m):\n");
	//вывод b(m)
	for (i=0; i<m; i++)
	{
			printf("%5d", b[i]);
	}

	getch();
}
