#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[10], i,x, temp;

	for (i = 0;i < 10;i++) 
		scanf("%d", &score[i]);
	
	for(x=0;x<10;x++)
		for (i = 1; i < 10-x;i++) {
			if (score[x] < score[x + i]) {
				temp = score[x];
				score[x] = score[x + i];
				score[x + i] = temp;
		} //if¹®

	}//for¹®

	for (i = 0;i < 10;i++)
		printf("%d ", score[i]);

	printf("\n");

}