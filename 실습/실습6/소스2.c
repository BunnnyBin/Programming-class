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

	printf("�л��� �� = ");
	scanf("%d", &n);

	ptr = malloc(sizeof(struct STUDENT)*n);

	for (i = 0; i < n; i++) {
		printf("%d��° �л�\n", i + 1);
		printf("�й� =");
		scanf("%d", &ptr[i].number);
		printf("���� = ");
		scanf("%d", &ptr[i].kor);
		printf("���� = ");
		scanf("%d", &ptr[i].eng);
		printf("���� = ");
		scanf("%d", &ptr[i].math);
	}

	for (i = 0; i < n; i++)
		printf("%d��° �л��� �й� = %d, ���� = %d, ���� = %d, ���� = %d\n", i+1, ptr[i].number, ptr[i].kor, ptr[i].eng, ptr[i].math); 
}