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

char* cutvalue(char *s);	//�������� ������������ ����� �� ������
void ptintlist(element *head, element *tail);	//����� ������ � ���� ������
void removelist (element **head);	//�������� ������
void delspace(char *st);	//�������� ������ �������� �� ������

void main()
{
	element *cur, *head, *tail;
	setlocale(0, "russian");

	char *st=new char[80];
	do
	{
		printf("������� ��� � ����� ������������ ����� ����� ������: ");
		gets(st);
		delspace(st);
		printf("\n");
	} while (strchr(st,' ')==0);
	char *s=new char[strlen(st)+1];
	strcpy(s, st);
	delete [] st;

	printf("\n��������� ������: ");
	//������ ������� ������
	head = new element;
	tail = head;
	head->p=NULL;
	head->n=NULL;
	head->value=atof(cutvalue(s));
	printf("%7.2f",head->value);

	//��������� ��������
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

	//�������� ������ ������������ x1*xn-1...
	element *cur2, *head2, *tail2;
	printf("\n������ ������������ (x1*xn; x2*xn-1; x3*xn-2 ... xn*x1): ");
	//������ ������� ������ ������
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
	//��������� ��������
	while (left)
	{
		cur2 =new element;
		//��������� ����� ������� �� ������� ������������
		tail2->n = cur2;
		cur2->p = tail2;
		cur2->n = NULL;
		tail2 = cur2;
		//��������� �������� ������ �������� ������ ������������
		cur2->value = (left->value)*(right->value);
		printf("; %7.2f",cur2->value);
		left = left->n;
		right= right->p;
	}
	//����� ������� � ������ �������
	printf("\n\n����������� ������\n");
	ptintlist(head, tail);
	printf("\n������ ������������\n");
	ptintlist(head2, tail2);

	//�������� �������
	removelist (&head);
	removelist (&head2);
 	getch();
}


char* cutvalue(char *s) //�������� ������������ ����� �� ������
{						//������ ������������� - ��������� �����
	static int i = 0;	//����������� ������ �������������� ����� ������ s
	int j = 0;			//������ ��� �������  ����� � ����� �
	char *c = new char[10];
	static const int l = strlen(s);
	while ((s[i] != ' ') && (i < l))	//����� ��������� ��������
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
	printf("����� � ������:\n");
	while (head)
	{
		printf("     %7.2f\n",head->value);
		head = head->n;
	}
	printf("����� � �����:\n");
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
		if (st[i]==' ') //������� ������, ���� ����� ���� �� ����� ����� ���
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
