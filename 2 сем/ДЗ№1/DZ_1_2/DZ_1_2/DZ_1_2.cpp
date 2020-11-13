// DZ_1_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <locale.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 

char* convert_to(double num, int base);
void print_result(double num,int base,char *result);

int menu(char *cmd)
{
	if (!strcmp(cmd,"input")) return 1;
	if (!strcmp(cmd,"convert")) return 2;
	if (!strcmp(cmd,"print")) return 3;
	if (!strcmp(cmd,"end")) return 0;
	return -1;
}

void main()
{
	setlocale(0, "russian");
	double num=10E+30;
	int base, key; 
	char cmd[10], *result=NULL;

	printf("��������� �������� ����� �� 10-� � 2/8/16-� ������� ���������\n\n");
	printf("����:\n	<input> ��� ����� �����\n	<convert> ��� ������ ��������� ������� ��������� � ��������������\n	<print> ��� ������ ���������������� �����\n	<end> ��� ������ �� ���������");
	printf("\n������� �������...\n");
	do
	{
		printf("\n<");
		scanf("%s",cmd);
		printf("\n");
		key = menu(cmd);
		switch (key)
		{
			case 1:
			{
				do
				{
					printf("������� ����� � ���������� ������� ���������: ");
					scanf("%lf",&num);
					if (num>10E+15) 
						printf("��� ����� �� ������� �������, ������� ��������\n");
				}while (num>10E+15);
				result=NULL;
				break;
			}
			case 2:
			{
				if (num==10E+30)
					printf("�� �� ����� �����\n");
				else 
				{
					bool b_key;
					do
					{
						printf("������� ��������� ������� ���������, � ������� ���������: ");
						scanf("%d",&base);
						b_key=((base!=2) && (base!=8) && (base!=16));
						if (b_key)
							printf("��������� ����� ���� 2/8/16\n");
					}while (b_key);
					result = convert_to(num, base);
					printf("����� ������� �������������\n");
				}
				break;
			}
			case 3:
			{
				print_result(num, base, result);
				break;
			}
			case -1: printf("�������� �������\n"); break;;
			case 0:	break;
		}
	} while (key !=0);

	printf("\n������� ����� ������� ��� ����������...");
	getch();
	delete [] result;
}

void print_result(double num, int base, char *result)
{
	if (result==NULL)
		printf("�������� ������\n");
	else
	{
		char sign[3];
		if (num<0)
			strcpy(sign,"1 ");
		else
			strcpy(sign,"1 ");
		printf("����� %.0lf � %d-� ������� ���������: %s%s\n", num, base, sign, result);
	}
}

char* convert_to(double num, int base) //��������� ����� � base-�� ������� ���������.
{
	double buf=num, ost;
	int i=0;
	char *converted = new char[64];
	//���� �����
	if (num<0) 
	{
		buf*=-1;
		num*=-1;
	}
	//������ �����
	while (buf!=0)
	{
		buf=(int)floor(buf/base);
		ost=num-buf*base;
		num=buf;
		if (ost>9) 
		{
			converted[i]=(char)(ost+55);
		}
		else
			converted[i]=(char)(ost+48);
		i++;
	}
	converted[i]='\0';
	
	int len=i-1;
	for (i=len; i>(len)/2; i--)
	{
		char b=converted[i];
		converted[i]=converted[len-i];
		converted[len-i]=b;
	}
	return converted;
} 