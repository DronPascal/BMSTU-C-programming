// LB_17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct element
{
	double num;
	element *p, *n;
};

element * newelement (element **head, element **tail);
void printlist (element *head);
void removelist (element *head);

int main()
{
	setlocale(0, "russian");
	element *head = NULL, *tail = NULL, *temp, *buf;
	FILE *f = NULL;
	char num[16], ch;
	//чтение файла и формирование первого списка
	if ((f = fopen("nums.txt", "r"))  ==  NULL)
	{
		printf("Невозможно открыть файл");
		getch();
		return 1;
	}
	int k = 0;
	while ((ch = getc(f))!= EOF) 
	{
		if (ch == ' ')
		{
			num[k] = '\0';
			(newelement(&head, &tail))->num = atof(num);
			k = 0;
		}
		else
		{
			num[k] = ch;
			k++;
		}
	}
	num[k] = '\0';
	(newelement(&head, &tail))->num = atof(num);
	fclose(f);

	printf("Сформированный список чисел:");
	printlist(head);

	//поиск минимума и максимума
	buf = head;
	double max,  min = max = buf->num;
	while (buf)
	{
		if (buf->num > max) max = buf->num;
		else if (buf->num < min) min  = 	buf->num;
		buf = buf->n;
	}
	//Формирование второго списка
	element *head2 = NULL, *tail2 = NULL;
	buf = head;
	while (buf)
	{
		(newelement(&head2, &tail2))->num = (buf->num) * min;
		buf = buf->n;
	}

	printf("\nПолученный список чисел:");
	printlist(head2);
	
	printf("\n\nМинимальный элемент списка: %lf", min);
	printf("\nМаксимальный элемент списка: %lf", max);

	removelist(head);
	removelist(head2);
	getch();
}

element * newelement (element **head, element **tail)
{
	element *temp = new element;
	if ((*head) == NULL)
	{
		*head = temp;
		*tail = temp;
		(*head)->p = NULL;
		(*tail)->n = NULL;
	}
	else 
	{
		(*tail)->n = temp;
		temp->p = (*tail);
		temp->n = NULL;
		(*tail) = temp;
	}
	return temp;
}

void printlist (element *head)
{
	while (head)
	{
		printf(" %lf", head->num);
		head = head->n;
	}
}

void removelist (element *head)
{
	element *p;
	while (head)
	{
		p = head;
		head = head->n;
		delete p;
	}
}
