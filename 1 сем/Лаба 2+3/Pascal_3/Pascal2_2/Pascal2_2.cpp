#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>

int main()
{
	bool p=0;
	double x,xn,sinn,k,n;
	int i,j;
	setlocale(0, "russian");	
		puts("Проверяемый x");
		scanf("%lf", &x);
		puts("Введите до какой степени k проверять");
		scanf("%lf", &k);
		xn=1;
		sinn=sin(xn);
		n=1;
		while ((n<=k) && (sinn>=0))
		{
			n=n+1;
			xn=xn*x;
			sinn=sin(xn);
				if (sinn<0)
				{
					p=true;
				}		
		}
		if (p==true) {printf("\nИстина, есть отрицательное значение sin(x^n)\nПервое равно %lf",sinn);} else {puts("\nЛожь, нет отрицательных значений sin(x^n)");}
		p=false;
	getch();
}