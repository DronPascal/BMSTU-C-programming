// LB_5.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

void main()
{
	srand (time(NULL));
	const int m=11;
	int i, j, l, k, n, A[m][m], S1=0, S2=0;
	setlocale(0, "russian");
	//����������
	puts("������� ������ ���������� ������� n*n\n");
	scanf("%d",&n);
	puts("����������� ������\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			A[i][j]=rand()%100;
			printf("%5d", A[i][j]);
		}
		puts("\n");
	}
	//���������
	printf("������ �������� ������������ (� ����������� ��� n%2=0):");
	for (i=0; i<(n+1)/2; i++)
	{
		for (j=i; j<n-i; j++)
		{
			if ((A[i][j] % 2) == 0)
			{
				S1+=A[i][j];
				printf("%5d", A[i][j]);
			}
		}
	}
	printf("\n������ ������� ������������:");
	for (i=(n+1)/2; i<n; i++)
	{
		for (j=n-i-1; j<i+1; j++)
		{
			if ((A[i][j] % 2) == 0)
			{
				S2+=A[i][j];
				printf("%5d", A[i][j]);
			}
		}
		
	}
	//�����
	printf("\n����� ������ ��������� ������� �������: %5d\n����� ������ ��������� ������ �������: %5d", S1, S2);
	getch();
}