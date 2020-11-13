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

	printf("���������� ��������� � �������� �������\n");
	printf("�������:\n	<f1> ��� ������ � (y = (x-1)/(x+2))\n	<f2> ��� ������ � (y = sin(x/2-1))\n	<end> ��� ������ �� ���������");
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
				printf("������� �������� [a;b]: ");
				scanf("%f %f",&a, &b);
				printf("����������� �������: y = (x-1)/(x+2)\n");
				printf("�������:\n	<1>, ���� ������ �������\n	<0> ���� �� ������:\n");
				printf("MIN?<"); scanf("%d", &mik); printf("MAX?<"); scanf("%d", &mak);
				minmax(a, b, ptr, mik, mak);	
				break;
			}
			case 2:
			{
				ptr=f2;
				printf("������� �������� [a;b]: ");
				scanf("%f %f",&a, &b);
				printf("����������� �������: y = sin(x/2-1)\n");
				printf("�������:\n	<1>, ���� ������ �������\n	<0> ���� �� ������:\n");
				printf("MIN?<"); scanf("%d", &mik); printf("MAX?<"); scanf("%d", &mak);
				minmax(a, b, ptr, mik, mak);	
				break;
			}
			case -1: printf("�������� �������"); break;;
			case 0:
			{
				break;
			}
		}
	} while (key !=0);
 	getch();
}