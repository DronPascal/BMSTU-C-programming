// Z3_1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "MINMAX.h"

int menu(char *cmd)
{
	if (!strcmp(cmd,"f1")) return 1;
	if (!strcmp(cmd,"f2")) return 2;
	if (!strcmp(cmd,"end")) return 0;
	return -1;
}

float f1 (float x)
{
	return ((x-1)/(x+2));
}

float f2 (float x)
{
	return (sin(x/2-1));
}

void main()
{
	float (*ptr)(float);
	float a, b;
	int mik, mak;
	char cmd[10];
	setlocale(0, "russian");

	printf("НАХОЖДЕНИЕ МАКСИМУМА И МИНИМУМА ФУНКЦИИ\n");
	printf("Введите:\n	<f1> для поиска в (y = (x-1)/(x+2))\n	<f2> для поиска в (y = sin(x/2-1))\n	<end> для выхода из программы");
	int key;
	do
	{
		printf("\n<");
		scanf("%s",cmd);
		key = menu(cmd);
		switch (key)
		{
			case 1:
			{
				ptr=f1;
				printf("Введите интервал [a;b]: ");
				scanf("%f %f",&a, &b);
				printf("Исследуемая функция: y = (x-1)/(x+2)\n");
				printf("Введите:\n	<1>, если хотите вывести\n	<0> если не хотите:\n");
				printf("MIN?<"); scanf("%d", &mik); printf("MAX?<"); scanf("%d", &mak);
				minmax(a, b, ptr, mik, mak);	
				break;
			}
			case 2:
			{
				ptr=f2;
				printf("Введите интервал [a;b]: ");
				scanf("%f %f",&a, &b);
				printf("Исследуемая функция: y = sin(x/2-1)\n");
				printf("Введите:\n	<1>, если хотите вывести\n	<0> если не хотите:\n");
				printf("MIN?<"); scanf("%d", &mik); printf("MAX?<"); scanf("%d", &mak);
				minmax(a, b, ptr, mik, mak);	
				break;
			}
			case -1: printf("Неверная команда"); break;;
			case 0:
			{
				break;
			}
		}
	} while (key !=0);
 	getch();
}