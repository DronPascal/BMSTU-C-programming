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

void printlist(element *head); //�������� ������� ������ ������
void removelist (element *head);	//�������� ������

void main()
{
	element *p, *n, *b, *first, *last;
	char msg[10];
	char k[8];
	setlocale(0, "russian");
	
	printf("������� �����, ��������, ���-�� ������� ��� <end> ��� ���������� �����\n");
	printf("\n������ �������:\n�����   ��������   ���-��\n");
	n=new element;
	scanf("\n%d %s %d",&(n->key), &(n->name), &(n->amount));
	n->n=NULL;
	first=n;
	last=n;
	while (scanf("\n%s",k), (strcmp(k,"end")))
	{
		n=new element;	//������� ����� ������
		n->key=atoi(k);
		scanf("%s %d",&(n->name), &(n->amount));
		if ((first->n)!=NULL) //� ������ ������ 1 ������
		{
			p=first;
			while (((p->n)!=NULL) && ((p->key)<=(n->key)))
			{
				b=p;
				p=p->n;
			}
			if (p==first) //���� ���� ����� ������ ������ ����� ������ ������
			{			//��������� � ������
				n->n=first;
				first=n;
			}
			else 
			if ((p==last) && ((p->key)<(n->key)))  //���� ���� ������ �������� ������ ����� ����������
			{			//������ � �����
				last->n=n; 
				last=n;
				n->n=NULL;
			}
			else		//����� ��������� ����� �������
			{
				b->n=n;
				n->n=p;
			}
		}
		else //� ������ 1 ������, ������
		{
			if ((n->key)<(first->key)) //���� ���� ����� ������ ������, �� ������ � ������
			{
				n->n=first;
				first=n;
			}
			else if ((n->key)>=(last->key)) //���� ���� ����� ������ ������ ��� �����, �� ������ � �����
			{
				last->n=n;
				last=n;
				n->n=NULL;
			}
		}
		n=new element;
	}
	if (first->n) delete n;

	//����� ������
	printf("\n������ �������");
	printlist(first);

	//�������� �������
	printf("\n���� ������ ������� �������, ������� <remove>. <stop> - ���������� ���������\n");
	printf("<");
	scanf("%s",msg);
	if (strcmp(msg,"remove")==0)
	{
		
		while (strcmp(msg,"stop"))
		{
			printf("\n������� ��� ������: ");
			int key;
			scanf("%d", &key);
			p=first;
			while (((p->key)!=key) && (p->n!=NULL))  //���������� � b ����� �������� �������� ��� NULL
			{
				b=p;
				p=p->n;
			}
			if ((p->key)==key)	//���� ���� �����
			{
				if (p==first)	//���� ���� ������� ������
				{
					first=p->n;
					delete p;
				}
				else 
				{
					if (p==last)	//���� ���� ������� ���������
					{
						b->n=NULL;
						last=b;
						delete p;
					}
					else	//���������� ������
					{
						b->n=p->n;
						delete p;
					}
				}
			}
			else	//���� ��� ������
			{
				printf("\n��� ������ � �������: %d\n",key);
			}			
		printf("�������:\n	<remove>, ���� ������ ������� ���\n	<stop> ����� ��������� ��������\n");
		while (printf("<"), scanf("%s",msg), ((strcmp(msg,"stop")!=0) && (strcmp(msg,"remove")!=0))) {printf("����� ������� �� ����������, ��������� ����\n");}
		}
		//����� ����� ��������
		printf("\n������ ������� ����� ��������:");
		printlist(first);
	}
	//�������� ������
	removelist(first);
 	getch();
}

void printlist(element *head)
{
	if (head->n)
	{
		printf("\n�����   ��������   ���-��\n");
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
			printf("\n�����   ��������   ���-��\n");
			printf("%5d   %8s %7d\n",(head->key), (head->name), (head->amount));
		}
		else printf("\n������ ������� ����\n");
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