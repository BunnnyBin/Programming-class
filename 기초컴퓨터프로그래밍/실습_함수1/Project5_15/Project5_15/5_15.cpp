#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


double celtofah(double cel)
{
	double f = cel * 1.8 + 32;
	return f;
}

double fahtocel(double fah)
{
	double c = (fah - 32) / 1.8;
	return c;
	
}

int main()
{
	double in;
	double fah, cel;
	scanf("%lf", &in);

	fah = celtofah(in);
	cel = fahtocel(in);

	printf("%.1f�� ȭ���µ��� �ٲٸ� %.1f\n", in, fah);
	printf("%.1f�� �����µ��� �ٲٸ� %.1f\n", in, cel);
}
