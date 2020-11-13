// DZ_2_Z2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
//#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int binarysearch (int *arr, int b, int num, int &counter, int a=0)
{
	counter++;
	int m = a+(b-a)/2;
	if (a-b != 0)
	{
		if (arr[m] == num) return m;
		else if (arr[m] < num) binarysearch(arr, b, num, counter, m+1);
		else if (arr[m] > num) binarysearch(arr, m, num, counter, a);
	}
	else if (arr[m] != num) return -1;	
}

int main(void)
{
	setlocale(LC_ALL,"Rus");
	//srand(time(NULL));
	int *arr, n;
	printf("������� ���-�� ��������� � �������: ");
	scanf("%d", &n);
	arr = new int [n];
	printf("�������������� ������:");
	for (int i=0; i<n; i++)
	{
		arr[i]=i*i;
		printf(" %d", arr[i]);
	}
	int k;
	printf("\n�������, ������ �������� ����: ");
	int num, counter=0;
	scanf("%d", &num);
	k = binarysearch(arr,n,num, counter);
	if (k != -1)
	{
		printf("\n������ ��������: %d", k);
		printf("\n�������: %d", arr[k]);
		printf("\n���-�� ������� ��������: %d", counter);
	}
	else printf("������� �� ������.");
	getch();
	
}