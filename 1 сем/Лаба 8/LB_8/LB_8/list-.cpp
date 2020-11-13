#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "list-.h"

void tiein (*p, *n) //прикрепление элемента в конец списка
{					//добавление элемента n к последнему (текущему) - p
	p -> n = n;
	n -> n = NULL;
	p = n;
}

//¬ставка c сортировкой по возрастанию p->key (номера детали)
void lsadd (*n, *first)
{

}