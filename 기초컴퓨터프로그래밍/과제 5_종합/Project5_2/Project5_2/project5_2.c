#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, mon;
	int totalday = 0, yoil;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, j;

	printf("년과 월을 입력하시오. ");
	scanf("%d %d", &year, &mon);

	for (i = 1900;i < year;i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			month[1] = 29;
		else month[1] = 28;

		for (j = 0;j < 12;j++)
			totalday += month[j];
	}//(year-1)년도까지 총일 계산

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		month[1] = 29;
	else month[1] = 28;         //year년의 윤년 계산
 
	for (i = 0;i < mon - 1;i++)
		totalday += month[i];   // (mon-1)달까지 총일 계산

	printf("        %4d %4d\n", year, mon);
	printf("SUN MON TUE WED TUR FRI SAT\n");

	yoil = (totalday + 1) % 7;  //yoil = mon달의 1일의 요일

	if (yoil == 0)
		printf("\n");
	for (i = 0;i < yoil;i++)    //1일 전까지 빈칸 출력
		printf("    ");

	for(i = 1;i <= month[mon-1];i++) {  //빈칸이후로 숫자 출력
		printf("%3d ", i);
		if (yoil++ % 7 == 6)
			printf("\n");
	}
	printf("\n20170299_김유빈\n");
}