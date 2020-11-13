// LB_15_b.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	setlocale(0, "russian");
	FILE *f, *g;
	int r;

	/* �������� �� ������ */
	if((f=fopen("first.dat", "wb"))==NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ���������� ����� f */
	int k=(rand()%5+1)*2;
	for (int i=0; i<k; i++)
	{
		r=rand()%131+30;
		fwrite(&r, sizeof(int), 1, f) ;
	}
	fclose(f);

	printf("\n����� ������� �����:\n");
	printf("���� f: ");
	/* �������� ��� ������ */
	if((f=fopen("first.dat","rb"))==NULL) 
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ������ ����� f */
	while ((fread(&r, sizeof r, 1, f))==1) 
	{
		printf("%d ", r);
	}
	fclose(f);

	//��������������
	/* �������� f ��� ������ */
	if((f=fopen("first.dat","rb"))==NULL) 
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* �������� g ��� ������ */
	if((g=fopen("second.dat", "wb"))==NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ���������� � ���� g */
	fseek(f, (k/2-1)*sizeof(r),0);
	for (int i=0; i<k; i++)
	{
		fread(&r, sizeof r, 1, f);
		fwrite(&r, sizeof r, 1, g);
		fseek(f, -sizeof(r),1);
		if (i%2==0)
			fseek(f, (i+1)*sizeof(r),1);
		if (i%2==1)
			fseek(f, -(i+1)*sizeof(r),1);
	}
	fcloseall();

	printf("\n����� ������� �����:\n");
	printf("���� g: ");
	/* �������� g ��� ������ */
	if((g=fopen("second.dat", "rb"))==NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ������ ����� f */
	while ((fread(&r, sizeof r, 1, g))==1) 
	{
		printf("%d ", r);
	}
	fclose(g);

	getch();
}
