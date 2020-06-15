#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int array[30][3];
	int temp;
	int i, j;

	srand(time(NULL));

	for (i = 0;i < 30;i++) {
		array[i][0] = i + 1;         //번호
		array[i][1] = rand() % 101;  //점수
	}

	for (i = 0;i < 30;i++) {
		array[i][2] = 1;
		for (j = 0;j < 30;j++)
			if (array[i][1] < array[j][1])
				array[i][2]++;
	}//등수
	
	printf("번호순\n");
	for (i = 0;i < 30;i++)
		printf("%2d번 %3d점 %2d등\n", array[i][0], array[i][1], array[i][2]);
		
	for(i=0;i<30;i++)                        //성적순으로 배열을 바꿈
		for (j = i;j < 30;j++) {
			if (array[i][1] < array[j][1])
				for (int k = 0;k<3;k++) {
					temp = array[i][k];
					array[i][k] = array[j][k];
					array[j][k] = temp;
				}
		}

	printf("성적순\n");
	for (i = 0;i < 30;i++)
		printf("%2d등 %3d점 %2d번\n", array[i][2], array[i][1], array[i][0]);

}