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

	/* открытие на запись */
	if((f=fopen("first.dat", "wb"))==NULL)
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* заполнение файла f */
	int k=(rand()%5+1)*2;
	for (int i=0; i<k; i++)
	{
		r=rand()%131+30;
		fwrite(&r, sizeof(int), 1, f) ;
	}
	fclose(f);

	printf("\nВЫВОД ПЕРВОГО ФАЙЛА:\n");
	printf("Файл f: ");
	/* открытие для чтения */
	if((f=fopen("first.dat","rb"))==NULL) 
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* чтение файла f */
	while ((fread(&r, sizeof r, 1, f))==1) 
	{
		printf("%d ", r);
	}
	fclose(f);

	//ПРЕОБРАЗОВАНИЕ
	/* открытие f для чтения */
	if((f=fopen("first.dat","rb"))==NULL) 
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* открытие g для записи */
	if((g=fopen("second.dat", "wb"))==NULL)
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* сохренение в файл g */
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

	printf("\nВЫВОД ВТОРОГО ФАЙЛА:\n");
	printf("Файл g: ");
	/* открытие g для чтения */
	if((g=fopen("second.dat", "rb"))==NULL)
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* чтение файла f */
	while ((fread(&r, sizeof r, 1, g))==1) 
	{
		printf("%d ", r);
	}
	fclose(g);

	getch();
}
