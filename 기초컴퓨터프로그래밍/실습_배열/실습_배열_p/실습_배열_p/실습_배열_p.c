#include <stdio.h>

int main(void)
{
	int a[10];
	int i, j, k, freq[10] = { 0 };

	for (i = 0; i<10; i++)
	{
		printf("%d 번째 점수를 입력하세요: ", i + 1);
		scanf_s("%d", &a[i]);
		printf("\n");
	} //점수 입력

	for (i = 0; i<10; i = i + 1)
	{
		k = a[i] / 10;

		if (a[i] == 100)
			freq[9] += 1;

		else
			freq[k] = freq[k] + 1;


	} //점수들의 십자리수대로 갯수(good idea)

	for (i = 0; i<9; i++)     // 0-9부터 80-89까지 
	{
		printf("%2d ~ %2d: ", i * 10, i * 10 + 9);
		for (j = 0; j<freq[i]; j++)  //j는 별표시
			printf("*");

		printf("\n");
	}

	printf("%2d ~ %2d: ", 90, 100);   //90-100를 따로 
	for (j = 0; j<freq[9]; j++)
		printf("*");

	printf("\n");

	return 0;
}