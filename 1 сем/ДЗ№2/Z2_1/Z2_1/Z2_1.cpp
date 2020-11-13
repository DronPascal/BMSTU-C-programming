// Z2_1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

void main()
{
	int i, j, n;
	char *str, b;
	srand (time(NULL));
	setlocale(0, "russian");
	//заполнение
	puts("Введите длину строки (до 50)\n");
	do
	{
	scanf("%d",&n);
	} while ((n>50) || (n<1));
	str = new char[n];
	puts("\nСортируемая по алфафиту строка: ");
	for (i=0; i<n; i++)
	{
		str[i]=(char)(rand()%26+65);
		printf("%c", str[i]);
	}
	for (i=0; i<n-1; i++)
	{
		for (j=0; j<n-i-1; j++)
		{
			if ((str[j]) > (str[j+1])) 
			{
				b=(str[j]);
				str[j]=str[j+1];
				str[j+1]=b;
			}
		}
	}

	puts("\nОтсортированная строка: ");
	for (i=0; i<n; i++)
	{
		printf("%c", str[i]);
	}	
	delete [] str;
	getch();
}
