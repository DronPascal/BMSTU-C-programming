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
	
	printf("БАЗА ДАННЫХ СВЕДЕНИЙ О ДОМАХ\n\n");
	printf("Введите:\n	1. Ввод данных о новом участке\n	2. Удаление данных об участке\n	3. Поиск по базе\n	4. Вывод на экран всей базы данных\n	5. Выход из программы");
	do
	{
		printf("\n<");
		scanf("%d", &cmd);
		switch (cmd)
		{
			case 1:
			{
				/* открытие на запись */
				if((f=fopen("database.dat", "a+b"))==NULL)
				{
					printf("\nНевозможно открыть файл\n");
					return 1;
				}
				/* сохранение в файл f */
				inputhouse(&r);
				fwrite(&r, sizeof r, 1, f);
				fclose(f);
				break;
			}
			case 2:
			{
				int num;
				printf("\nВведите номер дома в базе, который надо удалить: ");
				do{
					scanf("%d", &num);
					if (num<1) printf("Нумерация начинается с \"1\". Посторите ввод: ");
				} while (num<1);
				FILE *g;
				/* открытие на запись */
				if (dbtryopen(&f)) break;
				if((g=fopen("database2.dat", "wb"))==NULL)
				{
					printf("\nНевозможно открыть файл\n");
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
				if (remove("database.dat")) printf("\nОшибка удаления файла.\n");
				rename("database2.dat", "database.dat");
				if (num>=n)  printf("\nВ базе нет дома под этим номером.\n");
				else printf("\nДанные о доме успешно удалены\n");
				break;
			}
			case 3:
			{
				printf("	1. Определить фамилии владельцев, имеющих дома указанной этажности.\n	2. Вывести данные о домах, изготовленных из указанного материала.\n	3. Определить фамилии владельцев, дома которых построены из дерева после указанного срока.\n	<0> для возврата в главное меню.\n");
				int key2;
				do
				{
					printf("\nВведите номер типа поиска: ");
					scanf("%d", &key2);
					switch (key2)
					{
						case 1:
						{	
							if (dbtryopen(&f)) break;
							int fl;
							printf("\nВведите колличество этажей: ");
							scanf("%d", &fl);
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if (fl==r.floors)
								{
									if (n==1) printf("\nФамилии владельцев:\n");
									printf("	%d) %s\n", n, r.owner);
									n++;
								}
							}
							if (n==1) printf("Совпадений не найдено\n");
							fclose(f);
							break;
						}
						case 2:
						{	
							if (dbtryopen(&f)) break;
							char mat[15];
							printf("\nВведите название материала (brick, wooden,...): ");
							scanf("%s", &mat);
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if (strcmp(r.material, mat)==0) 
								{
									printf("\nДанные о %d-м доме:\n", n);
									houseinfo(r);
									n++;
								}
							}
							if (n==1) printf("Совпадений не найдено\n");
							fclose(f);
							break;
						}
						case 3:
						{	
							if (dbtryopen(&f)) break;
							int y;
							printf("\nВведите год: ");
							scanf("%d", &y);					
							int n=1;
							while ((fread(&r, sizeof r, 1, f))==1) 
							{	
								if ((r.year > y) && (strcmp(r.material, "wooden")==0))
								{
									if (n==1) printf("\nФамилии владельцев:\n");
									printf("	%d) %s\n", n, r.owner);
									n++;
								}
							}
							if (n==1) printf("Совпадений не найдено\n");
							fclose(f);
							break;
						}
						case 0: 
						{
							break;
						}
						default: 
						{
							printf("\nНеверная команда\n");
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
				printf("Неверная команда");
				break;
			}
		}
	} while (cmd !=5);

	printf("\n\nнажмите любую клавишу для завершения...");
	//remove("database.dat");
	getch();
	return 0;	
}

void inputhouse(house *cur)
{
	printf("\nВведите данные о доме:\n");
	printf("Колличество этажей: ");
	scanf("%d", &cur->floors);
	printf("Площадь: ");
	scanf("%lf", &cur->square);
	printf("Год: ");
	scanf("%d", &cur->year);
	printf("Материал (brick, wooden,...): ");
	scanf("%s", &cur->material);
	printf("Цена: ");
	scanf("%lf", &cur->cost);
	printf("Фамилия владельца: ");
	scanf("%s", &cur->owner);
}

void houseinfo(house cur)
{
	printf("	Колличество этажей: %d\n", cur.floors);
	printf("	Площадь: %lf\n", cur.square);
	printf("	Год: %d\n", cur.year);
	printf("	Материал (brick, wooden,...): %s\n", cur.material);
	printf("	Цена: %lf\n", cur.cost);
	printf("	Фамилия владельца: %s\n", cur.owner);	
}

bool dbtryopen(FILE **f)
{
	if((*f=fopen("database.dat", "rb"))==NULL)
	{
		printf("\nНевозможно открыть файл\n");
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
		printf("\nДанные о %d-м доме:\n", n);
		houseinfo(r);
		n++;
	}
	if (n==1) printf("\nБаза пуста.\n", n);
}