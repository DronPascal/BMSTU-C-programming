// DZ_2_Z1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct house{
	int floors;
	double square;
	int year;
	char material[15];
	double cost;
	char owner[30];
};

void inputhouse(house *cur);
void houseinfo(house cur);
void allinfo(FILE *f);
bool dbtryopen(FILE **f);



int main(void)
{
	setlocale(LC_ALL,"Rus");

	int cmd;
	FILE *f;
	house r;
	
	printf("���� ������ �������� � �����\n\n");
	printf("�������:\n	1. ���� ������ � ����� �������\n	2. �������� ������ �� �������\n	3. ����� �� ����\n	4. ����� �� ����� ���� ���� ������\n	5. ����� �� ���������");
	do
	{
		printf("\n<");
		scanf("%d", &cmd);
		switch (cmd)
		{
			case 1:
			{
				/* �������� �� ������ */
				if((f=fopen("database.dat", "a+b"))==NULL)
				{
					printf("\n���������� ������� ����\n");
					return 1;
				}
				/* ���������� � ���� f */
				inputhouse(&r);
				fwrite(&r, sizeof r, 1, f);
				fclose(f);
				break;
			}
			case 2:
			{
				int num;
				printf("\n������� ����� ���� � ����, ������� ���� �������: ");
				do{
					scanf("%d", &num);
					if (num<1) printf("��������� ���������� � \"1\". ��������� ����: ");
				} while (num<1);
				FILE *g;
				/* �������� �� ������ */
				if (dbtryopen(&f)) break;
				if((g=fopen("database2.dat", "wb"))==NULL)
				{
					printf("\n���������� ������� ����\n");
					break;
				}
				int n=1;
				while ((fread(&r, sizeof r, 1, f))==1) 
				{	
					if (n!=num) fwrite(&r, sizeof r, 1, g);
					n++; 
				}
				fclose(f);
				fclose(g);
				if (remove("database.dat")) printf("\n������ �������� �����.\n");
				rename("database2.dat", "database.dat");
				if (num>=n)  printf("\n� ���� ��� ���� ��� ���� �������.\n");
				else printf("\n������ � ���� ������� �������\n");
				break;
			}
			case 3:
			{
				printf("	1. ���������� ������� ����������, ������� ���� ��������� ���������.\n	2. ������� ������ � �����, ������������� �� ���������� ���������.\n	3. ���������� ������� ����������, ���� ������� ��������� �� ������ ����� ���������� �����.\n	<0> ��� �������� � ������� ����.\n");
				int key2;
				do
				{
					printf("\n������� ����� ���� ������: ");
					scanf("%d", &key2);
					switch (key2)
					{
						case 1:
						{	
							if (dbtryopen(&f)) break;
							int fl;
							printf("\n������� ����������� ������: ");
							scanf("%d", &fl);
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if (fl==r.floors)
								{
									if (n==1) printf("\n������� ����������:\n");
									printf("	%d) %s\n", n, r.owner);
									n++;
								}
							}
							if (n==1) printf("���������� �� �������\n");
							fclose(f);
							break;
						}
						case 2:
						{	
							if (dbtryopen(&f)) break;
							char mat[15];
							printf("\n������� �������� ��������� (brick, wooden,...): ");
							scanf("%s", &mat);
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if (strcmp(r.material, mat)==0) 
								{
									printf("\n������ � %d-� ����:\n", n);
									houseinfo(r);
									n++;
								}
							}
							if (n==1) printf("���������� �� �������\n");
							fclose(f);
							break;
						}
						case 3:
						{	
							if (dbtryopen(&f)) break;
							int y;
							printf("\n������� ���: ");
							scanf("%d", &y);					
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if ((r.year > y) && (strcmp(r.material, "wooden")==0))
								{
									if (n==1) printf("\n������� ����������:\n");
									printf("	%d) %s\n", n, r.owner);
									n++;
								}
							}
							if (n==1) printf("���������� �� �������\n");
							fclose(f);
							break;
						}
						case 0: 
						{
							break;
						}
						default: 
						{
							printf("\n�������� �������\n");
						}
					}
				} while (key2!=0);
				break;
			}
			case 4: 
			{
				if (dbtryopen(&f)) break;
				allinfo(f);
				fclose(f);
				break;
			}
			case 5:
			{
				break;
			}
			default: 
			{
				printf("�������� �������");
				break;
			}
		}
	} while (cmd !=5);

	printf("\n\n������� ����� ������� ��� ����������...");
	//remove("database.dat");
	getch();
	return 0;	
}

void inputhouse(house *cur)
{
	printf("\n������� ������ � ����:\n");
	printf("����������� ������: ");
	scanf("%d", &cur->floors);
	printf("�������: ");
	scanf("%lf", &cur->square);
	printf("���: ");
	scanf("%d", &cur->year);
	printf("�������� (brick, wooden,...): ");
	scanf("%s", &cur->material);
	printf("����: ");
	scanf("%lf", &cur->cost);
	printf("������� ���������: ");
	scanf("%s", &cur->owner);
}

void houseinfo(house cur)
{
	printf("	����������� ������: %d\n", cur.floors);
	printf("	�������: %lf\n", cur.square);
	printf("	���: %d\n", cur.year);
	printf("	�������� (brick, wooden,...): %s\n", cur.material);
	printf("	����: %lf\n", cur.cost);
	printf("	������� ���������: %s\n", cur.owner);	
}

bool dbtryopen(FILE **f)
{
	if((*f=fopen("database.dat", "rb"))==NULL)
	{
		printf("\n���������� ������� ����\n");
		return 1;
	}
	else return 0;
}

void allinfo(FILE *f)
{
	int n=1;
	house r;
	while ((fread(&r, sizeof r, 1, f))==1) 
	{	
		printf("\n������ � %d-� ����:\n", n);
		houseinfo(r);
		n++;
	}
	if (n==1) printf("\n���� �����.\n", n);
}