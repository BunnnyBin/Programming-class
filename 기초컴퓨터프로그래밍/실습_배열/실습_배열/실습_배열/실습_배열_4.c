#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[10], myscore, myrank = 1;
	int i;

	printf("10���� ������ �Է��ϼ���. \n");

	for (i = 0;i < 10;i++) 
		scanf("%d", &score[i]);
		

	printf("\n����� ������? ");
	scanf("%d", &myscore);
	
	for (i = 0; i< 10;i++) 
		if (myscore < score[i])
			myrank += 1;
	
	
	printf("\n����� %d��", myrank);
}