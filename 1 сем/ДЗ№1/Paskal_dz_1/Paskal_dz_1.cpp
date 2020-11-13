#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include "math.h"

float stepen(float a, float b)
{
	float ab=1;
	for (int i=1; i<=b; i++)
	{
		ab=ab*a;
	}
	return ab;
};
double stepen(double a, double b)
{
	double ab=1;
	for (int i=1; i<=b; i++)
	{
		ab=ab*a;
	}
	return ab;
};
int main()
{
	float e=2.718281;
	float x, y,xx,x2,a,tg,ex;
	setlocale(0, "russian");
	printf("e=%20.14lf",e);
	puts("\n¬ведите X");
	scanf("\n%lf", &x);
	xx=x*x;
	printf("\nx^2=%20.14lf",xx);
	x2=x-2;
	printf("\nx-2=%20.14lf",x2);
	a=xx*x2;
	printf("\nx^2*(x-2)=%20.14lf",a);
	tg=tan(a);
	printf("\ntg(x^2*(x-2)=%20.14lf",tg);
	ex=stepen(e,x);
	printf("\ne^x=%20.14lf",ex);
	y=tan(a)/ex;
	printf("\ntg(x^2*(x-2))/e^x=%20.14lf",y);
	getch();
}

