
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>

void main()
{
	double x, y, w, r1, r2, r3, max;
	setlocale(0, "russian");
	puts("¬ведите X, Y, W");
	scanf("%lf%lf%lf", &x, &y, &w);
	r1 = x + y / 2;
	r2 = x / 2;
	r3 = y * w;
	printf("\nX+Y/2=%6.2lf;\nX/2=%6.2lf\nY*W=%6.2lf", r1, r2, r3);
	if (r1 > r2)
	{
		if (r1 > r3)
		{
			max = pow(r1, 2) + 1;
		}
		else
		{
			max = pow(r3, 2) + 1;
		}
	}
	else
	{
		if (r2 > r3)
		{
			max = pow(r2, 2) + 1;
		}
		else
		{
			max = pow(r3, 2) + 1;
		}
	}
	printf("\nmax^2+1=%15.7lf", max);
	getch();
}