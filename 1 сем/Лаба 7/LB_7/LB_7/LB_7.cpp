// LB_7.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void delspace(char *st);

void main()
{
	int k=0, l;
	char s[41]={'\0'}, *ptr, *ptr2;
	bool v;
	setlocale(0, "russian");
	//заполнение
	puts("¬ведите строку");
	gets(s);
	//вывод
	printf("»значальна€ строка: %s\n", s);
	//вывод без лишних пробелов
	delspace(s);
	printf("—трока без лишних пробелов: %s\n", s);
	//обработка
	l=0;
	ptr2 = ptr = s;
	while (*ptr != '\0')
	{
		l++;
		if ((*ptr == ' ') || (*ptr == '.'))
		{
			if (l<5)
			{
				strcpy(ptr2, ptr);
				ptr=ptr2;
			}
			l=0;
			ptr2=ptr;
		}
		ptr++;
	}
	//вывод
	printf("Cтрока без коротких слов (<4): %s\n", s);
 	getch();
}

void delspace(char *st)
{
	int i=0;
	while (st[i+1]!='\0')
	{
		if (st[i]==' ') //удал€ем пробел, если после него не стоит буква
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
