#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double celtofah(double cel);
double fahtocel(double fah);

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