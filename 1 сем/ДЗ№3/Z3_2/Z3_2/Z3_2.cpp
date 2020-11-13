// Z3_2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct element
{
	double value;
	element *p, *n;
};

char* cutvalue(char *s);	//вырезаем вещественные числа из строки
void ptintlist(element *head, element *tail);	//вывод списка с двух сторон
void removelist (element **head);	//удаление списка
void delspace(char *st);	//удаление лишних пробелов из строки

void main()
{
	element *cur, *head, *tail;
	setlocale(0, "russian");

	char *st=new char[80];
	do
	{
		printf("Введите два и более вещественных числа через пробел: ");
		gets(st);
		delspace(st);
		printf("\n");
	} while (strchr(st,' ')==0);
	char *s=new char[strlen(st)+1];
	strcpy(s, st);
	delete [] st;

	printf("\nВведенный список: ");
	//первый элемент списка
	head = new element;
	tail = head;
	head->p=NULL;
	head->n=NULL;
	head->value=atof(cutvalue(s));
	printf("%7.2f",head->value);

	//остальные элементы
	char *c = cutvalue(s);
	while (strcmp(c,"\0")!=0)
	{
		cur = new element;
		cur->value = atof(c);
		tail->n = cur;
		cur->p = tail;
		cur->n = NULL;
		tail = cur;
		printf("; %7.2f",tail->value);
		c = cutvalue(s);
	}

	//создание списка произведений x1*xn-1...
	element *cur2, *head2, *tail2;
	printf("\nСписок произведений (x1*xn; x2*xn-1; x3*xn-2 ... xn*x1): ");
	//первый элемент нового списка
	head2 = new element;	
	tail2 = head2;
	head2->p = NULL;
	head2->n = NULL;
	
	cur2 = head2;
	element *left=head, *right=tail;
	cur2->value = (left->value)*(right->value);
	printf("%7.2f",cur2->value);
	left = left->n;
	right = right->p;
	//остальные элементы
	while (left)
	{
		cur2 =new element;
		//связываем новый элемент со списком произведений
		tail2->n = cur2;
		cur2->p = tail2;
		cur2->n = NULL;
		tail2 = cur2;
		//заполняем значение нового элемента списка произведений
		cur2->value = (left->value)*(right->value);
		printf("; %7.2f",cur2->value);
		left = left->n;
		right= right->p;
	}
	//вывод списков в разном порядке
	printf("\n\nИзначальный список\n");
	ptintlist(head, tail);
	printf("\nСписок произведений\n");
	ptintlist(head2, tail2);

	//удаление списков
	removelist (&head);
	removelist (&head2);
 	getch();
}


char* cutvalue(char *s) //вырезаем вещественные числа из строки
{						//каждое использование - следующее число
	static int i = 0;	//статический индекс обрабатываемой буквы строки s
	int j = 0;			//индекс для вставки  буквы в буфер с
	char *c = new char[10];
	static const int l = strlen(s);
	while ((s[i] != ' ') && (i < l))	//числа разделены пробелом
	{
		c[j] = s[i];
		j++;
		i++;
	}
	if (i <= l) 
	{
		c[j]='\0';
		i++;
		return c;
		
	}
	else return "\0";
};

void ptintlist(element *head, element *tail)
{
	printf("Вывод с начала:\n");
	while (head)
	{
		printf("     %7.2f\n",head->value);
		head = head->n;
	}
	printf("Вывод с конца:\n");
	while (tail)
	{
		printf("     %7.2f\n",tail->value);
		tail = tail->p;
	}
}

void removelist (element **head)
{
	while ((*head)->n)
	{
		*head = (*head)->n;
		delete (*head)->p;
	}
	delete *head;
	*head=NULL;
}

void delspace(char *st)
{
	int i=0;
	while (st[i+1]!='\0')
	{
		if (st[i]==' ') //удаляем пробел, если после него не стоит цифра или
			if (!(((st[i+1]>='0') && (st[i+1]<='9')) || (st[i+1]==',')))
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
