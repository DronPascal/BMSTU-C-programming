// LB_9.cpp : СОХРАНЕНИЕ ИЗ ФАЙЛА В ДРУГОЙ ФАЙЛ НЕЧЕТНЫХ ЧИСЕЛ В ОБРАТНОМ ПОРЯДКЕ 
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

	//формирование файла f
	/* открытие на запись */
	if((f=fopen("firstl.dat", "wb"))==NULL)
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* сохранение в файл f */
	printf("Введите числа, для завершения ввода введите <end>: ");
	char num[10];
	while (scanf("%s",num), strcmp(num,"end"))
	{
		r=atoi(num);
		fwrite(&r, sizeof r, 1, f) ;
	}
	fclose(f);
	
	//===========================================================
	printf("\nВЫВОД ПЕРВОГО ФАЙЛА:\n");
	printf("Файл f: ");
	/* открытие для чтения */
	if((f=fopen("firstl.dat","rb"))==NULL) 
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* чтение файла f */
	while ((fread(&r, sizeof r, 1, f))==1) 
	{
		printf("%d ", r);
		k++;
	}
	fclose(f);
	
	//===========================================================
	//формирование файла g
	/* открытие f для чтения */
	if((f=fopen("firstl.dat","rb"))==NULL) 
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* открытие g для записи */
	if((g=fopen("lirstf.dat", "wb"))==NULL)
	{
		printf("Невозможно открыть файл");
		return 1;
	}
	/* сохренение в файл g */
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
	printf("\nВЫВОД НЕЧЕТНЫХ В ОБРАТНОМ ПОРЯДКЕ:\n");
	printf("Файл g: ");
	/* открытие для чтения */
	if((g=fopen("lirstf.dat","rb"))==NULL) 
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
	return 0;	
}