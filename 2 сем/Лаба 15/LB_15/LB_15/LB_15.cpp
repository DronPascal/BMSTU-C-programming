// LB_15.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	setlocale(0, "russian");
	FILE *f=NULL;
	// �������� �� ������ 
	if ((f = fopen("file.txt", "w")) == NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	int str_k=rand()%30+1;
	for (int i=0; i<str_k; i++)
	{
		int len= rand()%31+1;
		char *str= new char[len+1];
		for (int j=0; j<len; j++)
		{
			str[j]=char(rand()%25+65);
		}
		str[len]='\0';
		fputs(str, f);
		fputs("\n", f);
	}
	fclose(f);
	
	//����� ��������������� �����
	printf("���� file.txt:\n");
	if ((f = fopen("file.txt", "r")) == NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	char str[81];
	while (fgets(str,80,f)!=NULL)
	{
		printf ("%s",str);
	}
	fclose(f);
	
	int n;
	do
	{
		printf("\n������� ����� ������ ���������� ��������� (0<n<%d): ", str_k);
		scanf("%d",&n);
		if (n>str_k)
			printf("� ����� ������ �����.");
		if (n<1)
			printf("����� ������ �� ����� ����� ������ �������.");
	}
	while ((n>str_k) || (n<1));

	//�������� �����
	FILE *f2=NULL;
	if ((f2 = fopen("file2.txt", "w")) == NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}

	if ((f = fopen("file.txt", "r")) == NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	int i=1;
	while ((i<n) && (fgets(str,80,f)!=NULL))
	{
		i++;
		fputs(str, f2);
	}

	fcloseall();
	remove("file.txt");
	rename("file2.txt", "file.txt");
	//����� ����������� �����
	printf("\n\n���� file.txt ����� �������� �����:\n");
	if ((f2 = fopen("file.txt", "r")) == NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	while (fgets(str,80,f2)!=NULL)
	{
		printf ("%s",str);
	}
	fclose(f2);
	

	getch();
}
