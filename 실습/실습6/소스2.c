#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT {
	int number;
	int kor;
	int eng;
	int math;
};

int main() {
	struct STUDENT * ptr;
	int n;
	int i;

	printf("학생의 수 = ");
	scanf("%d", &n);

	ptr = malloc(sizeof(struct STUDENT)*n);

	for (i = 0; i < n; i++) {
		printf("%d번째 학생\n", i + 1);
		printf("학번 =");
		scanf("%d", &ptr[i].number);
		printf("국어 = ");
		scanf("%d", &ptr[i].kor);
		printf("영어 = ");
		scanf("%d", &ptr[i].eng);
		printf("수학 = ");
		scanf("%d", &ptr[i].math);
	}

	for (i = 0; i < n; i++)
		printf("%d번째 학생의 학번 = %d, 국어 = %d, 영어 = %d, 수학 = %d\n", i+1, ptr[i].number, ptr[i].kor, ptr[i].eng, ptr[i].math); 
}