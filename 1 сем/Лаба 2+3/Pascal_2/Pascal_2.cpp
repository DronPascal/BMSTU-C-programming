#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	double x,y;
	setlocale(0, "russian");	
	puts("������� ����������� X � Y");
	scanf_s("%lf %lf", &x, &y);
	if (y>=(x+1)*(x+1))
	{
		if ((x+1)*(x+1)+y*y<=1)
		{
			printf("����� (%2.1lf;%2.1lf) ����� ���(��) ���������(�) � �(��) �����", x, y);
		}
		else
		{
			printf("����� (%2.1lf;%2.1lf) ����� ���(��) ���������(�)", x, y);
		}
	}
	else
	{
		if ((x+1)*(x+1)+y*y<=1)
		{
			printf("����� (%2.1lf;%2.1lf) ����� �(��) �����", x, y);
		}
		else
		{
			printf("����� (%2.1lf;%2.1lf) �� ����� �� ���(��) ���������(�), �� �(��) �����", x, y);
		}
	}
	getch();
}