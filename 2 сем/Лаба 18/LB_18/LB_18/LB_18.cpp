// LB_18.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime> 

struct node
{
	char word[30];
	int len;
	node *left, *right;
};

void TreeInput (node **root,int *arr=NULL);	//��������� ���������� � ������ ����� ���������
void addnode (node **root, node *cur);	//�������� ���� ���� � ������
void printtree (node *root, int level=0);	//����������� ������
void removenodesN (node **root, int &n); //������� ������� �� ����� (len)
void deletenode(node **root);	//������� ���� �� ������ 
void findleft(node **r, node **q);	//������� ���������� ������� (��������������� � deletenode)
void deletetree (node **root);	//������� ������
void NodesCount(node *root, int *K);

int main()
{
	setlocale(0, "russian");
	node *root=NULL;

	printf("������� ����� ����� Enter. ��� ���������� ����� ������� Enter.\n");
	
	int a_ind=0, *arr = new int [100];
	TreeInput(&root, arr);
	
	printf("����������� ������ ������:\n");
	printtree(root);
	
	if (root)
	{
		printf("\n������� �����, ����� ������� ������... (������� ��������): ");
		int K=0;
		NodesCount(root, &K);
		int minlen;
		scanf("%d", &minlen);
		printf("�����, ����� ������� ������ %d ���� (�������� ��������):\n", minlen);

		
		

		int begin = clock(); 
		removenodesN(&root, minlen);
		int end = clock();		
		printf("����� �������� �� ������ = %f ��\n", (float(end - begin))/1000);
		
		begin = clock(); 
		for (int i=K-1; i>=0; i--)
			if (arr[i]>minlen)
			{
				if (i==K-1)
					arr[i]=0;
				else
					for (int j=i; j<K-1; j++)
					arr[j]=arr[j+1];
			}
		end = clock();	
		printf("����� �������� �� ������� = %f ��\n", (float(end - begin))/1000);

		printf("\n��������������� ������:\n");
		printtree(root);

		printf("\n������� <yes> ��� ���������� ����� ���� Enter ��� ����������: ");
		char msg[10];
		fflush(stdin);
		gets(msg);
		if (strcmp(msg, "yes")==0)
		{
			printf("������� ����� ����� Enter. ��� ���������� ����� ������� Enter.\n");
			TreeInput(&root);
			printf("������ ����� ���������� ����� ������:\n");
			printtree(root);
		}
	}
	deletetree(&root);
	printf("\n������� ����� ������� ��� ����������...");
	getch();
}

void TreeInput (node **root,int *arr)
{
	char word[100];
	int i=0;
	while (gets(word), fflush(stdin), word[0]!='\0')
	{
		node *cur = new node;
		cur->left = NULL;
		cur->right = NULL;
		strcpy(cur->word, word);
		cur->len=strlen(word);
		addnode(root, cur);
		if (arr)
		{
		arr[i]= cur->len;
		i++;
		}
	}
}

void addnode (node **root, node *cur)
{
	if (*root)
	{
		if (cur->len < (*root)->len)
			if ((*root)->left) addnode(&((*root)->left), cur);
			else (*root)->left = cur;
		else 
			if ((*root)->right) addnode(&((*root)->right), cur);
			else (*root)->right = cur;
	}
	else
	{
		*root = cur;
	}
} 

void printtree (node *root, int level)
{
	if (root)
	{
		printtree(root->left, level + 1);
		for(int i = 0; i< level; i++) printf("    ");
		printf("%d\n", root->len);
		printtree(root->right, level + 1);
	}
	else if (level==0) printf("\n������ �����\n");
}

void removenodesN (node **root, int &n)	//MAIN TASK
{
	if (*root)
	{
		removenodesN(&(*root)->left, n);
		removenodesN(&(*root)->right, n);
		if ((*root)->len > n)
		{
			printf("	%s\n", (*root)->word);
			deletenode(root);
		}
	}
}

void deletenode(node **root)
{
				node *q = *root;
					//���� ������� ����� ���� �������� �������
				if (q->right == NULL) { *root = q->left; delete q; } 
				else
					//���� � ������� ��� �������� �������
				if (q->left == NULL) { *root = q->right; delete q; } 				
				else findleft(&q->left, &q); 	
}

void findleft(node **r, node **q)
{
	node *s;

	if ((*r)->right == NULL)
	{
		(*q)->len = (*r)->len;
		*q = *r;
		s = *r;
		*r = (*r)->left;
		delete s;
	}
	else findleft(&((*r)->right), q);
}

void deletetree (node **root)
{
	if (*root)
	{ 
		deletetree(&(*root)->left);
		deletetree(&(*root)->right);
		delete *root;
	}
}

void NodesCount(node *root, int *K)	//���-�� �����
{
	if (root)
	{
		NodesCount(root->left, K);
		NodesCount(root->right, K);
		(*K)++;
	}
}