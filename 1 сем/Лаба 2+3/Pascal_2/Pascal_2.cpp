#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	double x,y;
	setlocale(0, "russian");	
	puts("Введите проверяемые X и Y");
	scanf_s("%lf %lf", &x, &y);
	if (y>=(x+1)*(x+1))
	{
		if ((x+1)*(x+1)+y*y<=1)
		{
			printf("Точка (%2.1lf;%2.1lf) лежит над(на) параболой(е) и в(на) круге", x, y);
		}
		else
		{
			printf("Точка (%2.1lf;%2.1lf) лежит над(на) параболой(е)", x, y);
		}
	}
	else
	{
		if ((x+1)*(x+1)+y*y<=1)
		{
			printf("Точка (%2.1lf;%2.1lf) лежит в(на) круге", x, y);
		}
		else
		{
			printf("Точка (%2.1lf;%2.1lf) не лежит ни над(на) параболой(е), ни в(на) круге", x, y);
		}
	}
	getch();
}