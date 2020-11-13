// LB_9.cpp : ���������� �� ����� � ������ ���� �������� ����� � �������� ������� 
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	setlocale(0, "russian");

	int key;
	int i, r, k=0; 
	FILE *f, *g;

	//������������ ����� f
	/* �������� �� ������ */
	if((f=fopen("firstl.dat", "wb"))==NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ���������� � ���� f */
	printf("������� �����, ��� ���������� ����� ������� <end>: ");
	char num[10];
	while (scanf("%s",num), strcmp(num,"end"))
	{
		r=atoi(num);
		fwrite(&r, sizeof r, 1, f) ;
	}
	fclose(f);
	
	//===========================================================
	printf("\n����� ������� �����:\n");
	printf("���� f: ");
	/* �������� ��� ������ */
	if((f=fopen("firstl.dat","rb"))==NULL) 
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ������ ����� f */
	while ((fread(&r, sizeof r, 1, f))==1) 
	{
		printf("%d ", r);
		k++;
	}
	fclose(f);
	
	//===========================================================
	//������������ ����� g
	/* �������� f ��� ������ */
	if((f=fopen("firstl.dat","rb"))==NULL) 
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* �������� g ��� ������ */
	if((g=fopen("lirstf.dat", "wb"))==NULL)
	{
		printf("���������� ������� ����");
		return 1;
	}
	/* ���������� � ���� g */
	fseek(f,-sizeof(r),2);
	while (k>0)
	{
		fread(&r, sizeof r, 1, f);
		if ((r%2)==1) 
		{
			fwrite(&r, sizeof r, 1, g);
		}
		fseek(f,-2*(sizeof r), 1);
		k--;
	}
	fclose(f);
	fclose(g);
	
	//===========================================================
	printf("\n����� �������� � �������� �������:\n");
	printf("���� g: ");
	/* �������� ��� ������ */
	if((g=fopen("lirstf.dat","rb"))==NULL) 
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
	return 0;	
}