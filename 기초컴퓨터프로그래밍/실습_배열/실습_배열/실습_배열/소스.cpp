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
		freq[k] = freq[k] + 1;   
	} //점수들의 십자리수대로 갯수

	for (i = 0; i<10; i++) //먼저, 0-9부터
	{
		printf("%2d ~ %2d: ", i * 10, i * 10 + 9);  //주의: 90-100일 때 문제를 가짐
		for (j = 0; j<freq[i]; j++)  //j는 별표시
			printf("*");

		printf("\n");
	}
	return 0;
}