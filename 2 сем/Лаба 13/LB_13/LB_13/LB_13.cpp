// LB_13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void delspace(char *st);

void main()
{
	char *ptr, *s=new char[100], *maxposl, *maxposl_end;
	int maxlen=0;
	setlocale(0, "russian");
	//заполнение
	puts("Введите строку, для завершения ввода строк введите <end>:");
	while (scanf("\n%s",s), (strcmp(s,"end")))
	{
		delspace(s);
		int i=1;
		printf("Cтрока: %s\n", s);
		ptr=strchr(s,'*');
		while (ptr!=NULL)
		{
			char *buf=ptr;
			printf("\nАдреса %d-й последовательности: %p\n", i, ptr);
			printf("Адреса элементов: ");
			int len=0;
			do
			{
				printf(" %p", ptr);
				ptr++;
				len++;
			}while (*ptr=='*');

			printf("\nДлина последовательности: %d\n", len);
			if (len>maxlen) 
			{
				maxlen=len;
				maxposl=buf;
				maxposl_end=ptr;
			}
			ptr=strchr(ptr,'*');
			i++;
		}
		printf("\nУдаление первой самой длинной последовательности из '*'...\n");
		strcpy(maxposl, maxposl_end);
		printf("Преобразованная строка: %s\n", s);
		printf("\n----------------------------------------------------------\n");
		puts("\nВведите строку, для завершения ввода строк введите <end>:");
	}	
}

void delspace(char *st)
{
	int i=0;
	while (st[i+1]!='\0')
	{
		if (st[i]==' ') //удаляем пробел, если после него не стоит буква
			if (!(((st[i+1]>='a') && (st[i+1]<='z')) || ((st[i+1]>='A') && (st[i+1]<='Z')) || ((st[i+1]>='0') && (st[i+1]<='9'))))
			{
				char *ptr=&st[i]; 
				strcpy(ptr,ptr+1); 
				i--;
			}
		i++;
	}

	char *ptr =st;
	if (st[0]==' ') 
		strcpy(ptr,ptr+1);
	if (st[strlen(st)-1]==' ') 
		st[strlen(st)-1]='\0';
}