// LB_8.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct element
     { char name[11]; 
       int key, amount;
	   element *n;
     };

void printlist(element *head); //прототип функции вывода списка
void removelist (element *head);	//удаление списка

void main()
{
	element *p, *n, *b, *first, *last;
	char msg[10];
	char k[8];
	setlocale(0, "russian");
	
	printf("Введите номер, название, кол-во деталей ИЛИ <end> для завершения ввода\n");
	printf("\nСписок деталей:\nНОМЕР   НАЗВАНИЕ   КОЛ-ВО\n");
	n=new element;
	scanf("\n%d %s %d",&(n->key), &(n->name), &(n->amount));
	n->n=NULL;
	first=n;
	last=n;
	while (scanf("\n%s",k), (strcmp(k,"end")))
	{
		n=new element;	//создаем новую запись
		n->key=atoi(k);
		scanf("%s %d",&(n->name), &(n->amount));
		if ((first->n)!=NULL) //в списке больше 1 детали
		{
			p=first;
			while (((p->n)!=NULL) && ((p->key)<=(n->key)))
			{
				b=p;
				p=p->n;
			}
			if (p==first) //если ключ новой детали меньше ключа первой детали
			{			//вставляем в начало
				n->n=first;
				first=n;
			}
			else 
			if ((p==last) && ((p->key)<(n->key)))  //если ключ нового элемента больше ключа последнего
			{			//ставим в конец
				last->n=n; 
				last=n;
				n->n=NULL;
			}
			else		//иначе вставляем перед текущим
			{
				b->n=n;
				n->n=p;
			}
		}
		else //в списке 1 деталь, тогода
		{
			if ((n->key)<(first->key)) //если ключ новой детали меньше, то ставим в начало
			{
				n->n=first;
				first=n;
			}
			else if ((n->key)>=(last->key)) //если ключ новой детали больше или равен, то ставим в конец
			{
				last->n=n;
				last=n;
				n->n=NULL;
			}
		}
		n=new element;
	}
	if (first->n) delete n;

	//вывод списка
	printf("\nСписок деталей");
	printlist(first);

	//Удаление деталей
	printf("\nЕсли хотите удалить элемент, введите <remove>. <stop> - завершение программы\n");
	printf("<");
	scanf("%s",msg);
	if (strcmp(msg,"remove")==0)
	{
		
		while (strcmp(msg,"stop"))
		{
			printf("\nВведите код детали: ");
			int key;
			scanf("%d", &key);
			p=first;
			while (((p->key)!=key) && (p->n!=NULL))  //записываем в b адрес искомого элемента или NULL
			{
				b=p;
				p=p->n;
			}
			if ((p->key)==key)	//если есть адрес
			{
				if (p==first)	//если надо удалить первый
				{
					first=p->n;
					delete p;
				}
				else 
				{
					if (p==last)	//если надо удалить последний
					{
						b->n=NULL;
						last=b;
						delete p;
					}
					else	//посередине списка
					{
						b->n=p->n;
						delete p;
					}
				}
			}
			else	//если нет адреса
			{
				printf("\nНет детали с номером: %d\n",key);
			}			
		printf("Введите:\n	<remove>, если хотите удалить еще\n	<stop> чтобы завершить удаление\n");
		while (printf("<"), scanf("%s",msg), ((strcmp(msg,"stop")!=0) && (strcmp(msg,"remove")!=0))) {printf("Такой команды не существует, повторите ввод\n");}
		}
		//Вывод после удаления
		printf("\nСписок деталей после удаления:");
		printlist(first);
	}
	//удаление списка
	removelist(first);
 	getch();
}

void printlist(element *head)
{
	if (head->n)
	{
		printf("\nНОМЕР   НАЗВАНИЕ   КОЛ-ВО\n");
		while (head->n)
		{	
			printf("%5d   %8s %7d\n",(head->key), (head->name), (head->amount));	
			head=head->n;	
		}
		printf("%5d   %8s %7d\n",(head->key), (head->name), (head->amount));
	}
	else 
	{
		if (head)
		{
			printf("\nНОМЕР   НАЗВАНИЕ   КОЛ-ВО\n");
			printf("%5d   %8s %7d\n",(head->key), (head->name), (head->amount));
		}
		else printf("\nСПИСОК ДЕТАЛЕЙ ПУСТ\n");
	}
}

void removelist (element *head)
{
	element *p;
	while (head)
	{
		p=head;
		head = head->n;
		delete p;
	}
}