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
	puts("����������� x");
	scanf("%lf", &x);
	puts("������� �� ����� ������� k ���������");
	scanf("%lf", &k);
	xn=x;					//�������� �������� � x^1=x
	for (n=1; n<=k; n++)
	{
		sinn=sin(xn);		//������� �����
		if (sinn<0)			//���� �� ������ ����, �� ����������� p true, � otr ��� ��������
		{
			p=true;
			otr=sinn;
		}	
		xn=xn*x;			//��������� � ��������� ������� �����
	}
	if (p==true)
	{
		printf("\n������, ���� ������������� �������� sin(x^n)\n��������� ����� �������� ����� %lf",otr);
	} 
	else 
	{
		puts("\n����, ��� ������������� �������� sin(x^n)");
	}
	p=false;
	getch();
}
