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
		puts("����������� x");
		scanf("%lf", &x);
		puts("������� �� ����� ������� k ���������");
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
		if (p==true) {printf("\n������, ���� ������������� �������� sin(x^n)\n������ ����� %lf",sinn);} else {puts("\n����, ��� ������������� �������� sin(x^n)");}
		p=false;
	getch();
}