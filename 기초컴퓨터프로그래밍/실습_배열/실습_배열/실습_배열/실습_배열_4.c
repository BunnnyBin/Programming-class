#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[10], myscore, myrank = 1;
	int i;

	printf("10명의 점수를 입력하세요. \n");

	for (i = 0;i < 10;i++) 
		scanf("%d", &score[i]);
		

	printf("\n당신의 점수는? ");
	scanf("%d", &myscore);
	
	for (i = 0; i< 10;i++) 
		if (myscore < score[i])
			myrank += 1;
	
	
	printf("\n당신은 %d등", myrank);
}