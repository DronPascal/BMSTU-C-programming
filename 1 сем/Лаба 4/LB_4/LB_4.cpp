// LB_4.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

void main()
{
	srand (time(NULL));
	const int n=60;
	int i, j, S[n], buf;
	setlocale(0, "russian");
	puts("Изначальный массив\n");
	for (i=0; i<n; i++)
	{
		S[i]=i+1;
		printf("%4d", S[i]);
	}

	for (i=n/3-1; i>0; i--)
	{
		buf=S[i];
		for (j=i; j<i*3; j++)
		{
			S[j]=S[j+1];
		}
		S[i*3]=buf;	
	}
	puts("\nПреобразованный массив\n");
	for (i=0; i<n; i++)
	{
		printf("%4d", S[i]);
	}
	getch();
}