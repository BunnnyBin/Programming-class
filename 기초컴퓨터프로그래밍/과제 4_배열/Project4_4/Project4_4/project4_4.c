#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int score[30], rank[30];
	int i, j;

	for (i = 0;i < 30;i++)
		score[i] = rand() % 101;     //점수 입력, 난수 함수 사용


	for (i = 0;i < 30;i++) {         //순위 계산
		rank[i] = 1;   //각 점수마다 순위 '1'로 초기화
		for (j = 0;j < 30;j++)
			if (score[i] < score[j])
				rank[i]++;
	}

	printf("번호순\n\n");
	for (i = 0;i < 30;i++)   //i+1번호순으로 반복
		printf("%2d번  %3d점  %2d등\n",i + 1, score[i], rank[i]);

	printf("성적순\n");
	for (i = 0;i < 30;i++)
		for (j = 0;j < 30;j++)
			if (rank[j] == i + 1)  //i+1등에 해당하는 j+1번 학생
				printf("%2d등  %3d점  %2d번\n", i + 1, score[j], j + 1);
	printf("20170299 김유빈\n\n");
}