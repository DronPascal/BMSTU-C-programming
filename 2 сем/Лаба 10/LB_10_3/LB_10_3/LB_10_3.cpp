// LB_11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
void scanC(int *head, int n);
void printC(int *head, int n);
void main()
{
	int n, i, el, *C, *head, S=0, P=1, D;
	setlocale(0, "russian");
	printf("������� ������ �������: ");
	scanf("%d", &n);
	C = new int[n];
	head=C;
	printf("����� ������� ��������: %p\n", head);
	printf("������� �������� ������:\n");
	scanC(head, n);
	printf("\n�������� ������������ ������: ");
	printC(head, n);
	for (i=0; i<n; i++)
	{
		el=*(C+i);
		S+=el;
		P*=el;
	}
	D=P/S;
	printf("\n������������ ���������: %d\n", P);
	printf("����� ���������: %d\n", S);
	*C=D;
	head=C;
	printf("������� ������������ � ����� ���������: %d\n", D);
	printf("������ �������: %d\n", *head);
	printf("�������� ���������������� ������: ");
	printC(head, n);
	delete [] C;
	getch();
}
void scanC(int *head, int n)
{
	for (int i=0; i<n; i++)
	{
		scanf("%d", (head+i));
	}
}

void printC(int *head, int n)
{
for (int i=0; i<n; i++)
	{
		printf("%d ", *(head+i));
	}
}