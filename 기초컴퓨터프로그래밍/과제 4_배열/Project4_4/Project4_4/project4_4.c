#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int score[30], rank[30];
	int i, j;

	for (i = 0;i < 30;i++)
		score[i] = rand() % 101;     //���� �Է�, ���� �Լ� ���


	for (i = 0;i < 30;i++) {         //���� ���
		rank[i] = 1;   //�� �������� ���� '1'�� �ʱ�ȭ
		for (j = 0;j < 30;j++)
			if (score[i] < score[j])
				rank[i]++;
	}

	printf("��ȣ��\n\n");
	for (i = 0;i < 30;i++)   //i+1��ȣ������ �ݺ�
		printf("%2d��  %3d��  %2d��\n",i + 1, score[i], rank[i]);

	printf("������\n");
	for (i = 0;i < 30;i++)
		for (j = 0;j < 30;j++)
			if (rank[j] == i + 1)  //i+1� �ش��ϴ� j+1�� �л�
				printf("%2d��  %3d��  %2d��\n", i + 1, score[j], j + 1);
	printf("20170299 ������\n\n");
}