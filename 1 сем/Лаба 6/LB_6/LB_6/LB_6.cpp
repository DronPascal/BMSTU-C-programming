// LB_6.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include "sorting.h"

using namespace std;

void main()
{
	const int m=100;
	int i, n;
	char S[m];
	srand (time(NULL));
	setlocale(0, "russian");
	//заполнение
	puts("Введите длину строки\n");
	scanf("%d",&n);
	puts("\nОбрабатываемая строка: ");
	for (i=0; i<n; i++)
	{
		S[i]=(char)(rand()%94+33);
		printf("%c", S[i]);
	}

	latin (S, n);
	numerals (S, n);
	another (S, n);

	getch();
}
