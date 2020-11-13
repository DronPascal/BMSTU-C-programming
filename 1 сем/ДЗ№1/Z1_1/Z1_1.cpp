#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>

void main()
{
	//Надо вычислить y=tg(x^2*(x-2))/e^x, x вводится с клавиатуры.	
	//Вычислим по шагам используя тип данных float (7 знаковых цифр).
	float exp = 2.718281;
	float x, y, xx, x2, a, tg, expx;
	setlocale(0, "russian");
	printf("exp=%f", exp);
	puts("\nВведите X=");
	scanf("%f", &x);
	xx = x * x;
	printf("\n1) x^2=%f", xx);
	x2 = x - 2;
	printf("\n2) x-2=%f", x2);
	a = xx * x2;
	printf("\n3) x^2*(x-2)=%f", a);
	tg = tanf(a);
	printf("\n4) tg(x^2*(x-2)=%f", tg);
	expx = powf(exp, x);
	printf("\n5) e^x=%f", expx);
	y = tan(a) / expx;
	printf("\n6) tg(x^2*(x-2))/e^x=%15.13f", y);
	getch();
}