#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "list-.h"

void tiein (*p, *n) //������������ �������� � ����� ������
{					//���������� �������� n � ���������� (��������) - p
	p -> n = n;
	n -> n = NULL;
	p = n;
}

//������� c ����������� �� ����������� p->key (������ ������)
void lsadd (*n, *first)
{

}