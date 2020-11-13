#include "sorting.h"
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>



void latin (char S[], int n)
{
	printf ("\nЛатинские буквы: ");
	for (int i=0; i<n; i++)
	{
		if ((S[i]>='a' && S[i]<='z') || (S[i]>='A' && S[i]<='Z'))
		{
			printf ("%c ", S[i]);
		}
	}
}

void numerals (char S[], int n)
{
	printf ("\nЦифры: ");
	for (int i=0; i<n; i++)
	{
		if (S[i]>='0' && S[i]<='9')
		{
			printf ("%c ", S[i]);
		}
	}
}

void another (char S[], int n)
{
	printf ("\nПрочие символы: ");
	for (int i=0; i<n; i++)
	{
		if (((S[i]>='a' && S[i]<='z') || (S[i]>='A' && S[i]<='Z') || (S[i]>='0' && S[i]<='9'))==0)
		{
			printf ("%c ", S[i]);
		}
	}
}