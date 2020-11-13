#include "MINMAX.h"
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <conio.h>

void minmax(float a, float b, float (*ptr)(float), int mi, int ma)
{
	setlocale(0, "russian");
	float max, min;
	max=min=ptr(a);
	for (float x=a; x<b; x=x+0.01)
	{
		float y = ptr(x);
		if (y>max) max=y;
		if (y<min) min=y;
	}
	if (mi==1)
	{
		printf("\nMIN=%f", min);
	}
	if (ma==1)
	{
		printf("\nMAX=%f", max);
	}
	
}