#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, mon;
	int totalday = 0, yoil;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, j;

	printf("��� ���� �Է��Ͻÿ�. ");
	scanf("%d %d", &year, &mon);

	for (i = 1900;i < year;i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			month[1] = 29;
		else month[1] = 28;

		for (j = 0;j < 12;j++)
			totalday += month[j];
	}//(year-1)�⵵���� ���� ���

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		month[1] = 29;
	else month[1] = 28;         //year���� ���� ���
 
	for (i = 0;i < mon - 1;i++)
		totalday += month[i];   // (mon-1)�ޱ��� ���� ���

	printf("        %4d %4d\n", year, mon);
	printf("SUN MON TUE WED TUR FRI SAT\n");

	yoil = (totalday + 1) % 7;  //yoil = mon���� 1���� ����

	if (yoil == 0)
		printf("\n");
	for (i = 0;i < yoil;i++)    //1�� ������ ��ĭ ���
		printf("    ");

	for(i = 1;i <= month[mon-1];i++) {  //��ĭ���ķ� ���� ���
		printf("%3d ", i);
		if (yoil++ % 7 == 6)
			printf("\n");
	}
	printf("\n20170299_������\n");
}