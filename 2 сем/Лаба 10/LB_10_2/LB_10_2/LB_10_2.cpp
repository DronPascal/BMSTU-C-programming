// LB_10_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
void main()
{
	double x, y, y1, y2, Y=1, ap, op;
	setlocale(0, "russian");
	printf("Введите x:");
	scanf("%lf", &x);
	y1=(exp(x)+exp(-x))/2;
	y2=(exp(x)-exp(-x))/2;
	y=(y1*y1)-(y2*y2);
	printf("y1= %20.16lf\n",y1);
	printf("y2= %20.16lf\n",y2);
	printf("y= %20.16lf\n",y);
	ap=abs(Y-y);
	op=ap/Y;
	printf("Точное значение y= %20.16lf\n",Y);
	printf("Абсолютная погрешность ap= %20.16lf\n",ap);
    printf("Относительная погрешность op= %20.16lf\n",op);
	getch();
}

