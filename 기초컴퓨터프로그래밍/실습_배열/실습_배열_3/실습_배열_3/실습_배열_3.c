#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[10], j, i;

	for (i = 0;i < 10;i++)
		scanf("%d", &score[i]);

	for (i = 0;i < 9; i++) {    //0-9부터 80-89까지
		printf("\n%-3d-%-3d:", i * 10, i * 10 + 9);

		for (j = 0;j < 10;j++)
			if (score[j] / 10 == i)
				printf("*");
	}

	printf("\n%-3d-%-3d:", 90, 100);    //90-100 따로
	for (i = 0;i < 10;i++)
		if (score[i] / 10 == 9 || score[i] / 10 == 10)
			printf("*");


	printf("\n");

}