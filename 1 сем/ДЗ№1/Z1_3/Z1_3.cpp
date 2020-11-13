#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>

void main()
{
	int k;
	double pr, e, S, fact;		//S - сумма эл-в ряда
	setlocale(0, "russian");
	puts("Введите точность (e)");
	scanf("%lf", &e);
	printf("Точность=%16.15lf", e);
	S = 1;					//Нулевой элемент равен 1
	k = 1;					//Начинаем с k=1
	fact = 1;
	pr = 1 / fact;		//Считаем первый элемент ряда
	while(pr > e)			//Проверяем текущий элемент с заданной точностью		
	{					
		S += pr;			//Прибавляем текущий элемент к сумме
		k += 1;
		fact *= k;
		pr = 1 / fact;	//Считаем следующий
	}		
	printf("\nПоследний элемент=%16.15lf;", 1 / (fact / k)); 
	printf("\nКол-во эл-в=%d;", k);
	printf("\nСумма ряда=%16.15lf", S); 
	getch();
}