#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>

void main()
{
	bool p=0;
	double x,xn,sinn,k,n,otr;
	int i,j;
	setlocale(0, "russian");	
	puts("Проверяемый x");
	scanf("%lf", &x);
	puts("Введите до какой степени k проверять");
	scanf("%lf", &k);
	xn=x;					//начинаем проверку с x^1=x
	for (n=1; n<=k; n++)
	{
		sinn=sin(xn);		//считаем синус
		if (sinn<0)			//если он меньше нуля, то присваиваем p true, а otr это значение
		{
			p=true;
			otr=sinn;
		}	
		xn=xn*x;			//переходим к следующей степени числа
	}
	if (p==true)
	{
		printf("\nИстина, есть отрицательное значение sin(x^n)\nПоследнее такое значение равно %lf",otr);
	} 
	else 
	{
		puts("\nЛожь, нет отрицательных значений sin(x^n)");
	}
	p=false;
	getch();
}
