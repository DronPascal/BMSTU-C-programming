// Con1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include "Nod.h"

void main()
{
	int a,b;
	setlocale (0, "russian");
	puts ("������� ��� ����������� �����:");
	scanf ("%d %d", &a, &b);
	printf ("��� %d � %d = %d.\n", a, b, nod(a,b));
	puts ("������� ����� ������� ��� ����������...");
	getch();
}

