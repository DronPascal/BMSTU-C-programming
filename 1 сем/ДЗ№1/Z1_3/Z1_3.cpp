#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	int k;
	double pr, e, S, fact;		//S - ����� ��-� ����
	setlocale(0, "russian");
	puts("������� �������� (e)");
	scanf("%lf", &e);
	printf("��������=%16.15lf", e);
	S = 1;					//������� ������� ����� 1
	k = 1;					//�������� � k=1
	fact = 1;
	pr = 1 / fact;		//������� ������ ������� ����
	while(pr > e)			//��������� ������� ������� � �������� ���������		
	{					
		S += pr;			//���������� ������� ������� � �����
		k += 1;
		fact *= k;
		pr = 1 / fact;	//������� ���������
	}		
	printf("\n��������� �������=%16.15lf;", 1 / (fact / k)); 
	printf("\n���-�� ��-�=%d;", k);
	printf("\n����� ����=%16.15lf", S); 
	getch();
}