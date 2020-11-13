// LB_16.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime.>
using namespace std;

double average(int *arr, int n)	//�������
{
    if (n == 1)
        return arr[n - 1];
    return ((n-1) * average(arr, n - 1) + arr[n - 1])/n;
}

void average_proc(int *arr, int n, double &sr) //���������
{
    if (n == 1)
        sr = arr[n - 1];
    sr =((n-1) * average(arr, n - 1) + arr[n - 1])/n;
}

void main()
{
	int *arr, n;
	setlocale(0, "russian");
	srand(time(NULL));

	//����������
	do {
		printf("������� ������ ������� (n>0): ");
		scanf ("%d", &n);
	} while (n<1);
	
	arr = new int [n];

	printf("\n������:");
	for (int i=0; i<n; i++)
	{
		arr[i]=rand()%11;
		printf(" %d", arr[i]);
	}
	
	double sr;
	average_proc(arr, n, sr);
	printf("\n������� �������� ������� ����������� ����������: %lf", sr);
	printf("\n������� �������� ������� ����������� ��������: %lf", average(arr, n));

	delete [] arr;
	getch();
}