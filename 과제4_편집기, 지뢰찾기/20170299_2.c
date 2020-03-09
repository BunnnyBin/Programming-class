#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int block[9][19] = { 0 };   //��ź(-1)�� ��ź ����(0,1,2,3...)
	int mask[9][19] = { 0 };   //0: ����, 1: ����
	int row[20], line[20];   //��ź ������ ��ź �ߺ� ����
	char x, y;   //����ڰ� ���� ����� ��,��
	int r, w;
	int count;  //���� Ƚ��(��ź���� �� ��������)
	int i,j;

	printf("***************GAME START***************\n");
	srand(time(NULL));
	for (i = 0;i < 20;i++) {
		row[i] = rand() % 9 ;
		line[i] = rand() % 19;

		for (j = 0;j < i;j++) 
			if (row[i] == row[j] && line[i] == line[j]) {
				i--;
				break;
			} //��ź �ߺ� ����
		if (row[i+1] == row[j] && line[i+1] == line[j])
			continue;

		block[row[i]][line[i]] = -1;
	}//��ź ����

	for(i=0;i<9;i++)
		for (j = 0;j < 19;j++) 
			if (block[i][j] != -1) {      //��ź(-1)�� �״��
				if (i - 1 >= 0 && j - 1 >= 0)
					if (block[i - 1][j - 1] == -1)
						block[i][j]++;
				if (i - 1 >= 0)
					if (block[i - 1][j] == -1)
						block[i][j]++;
				if (i - 1 >= 0 && j + 1 < 19)
					if (block[i - 1][j + 1] == -1)
						block[i][j]++;
				if (j - 1 >= 0)
					if (block[i][j - 1] == -1)
						block[i][j]++;
				if (j + 1 < 19)
					if (block[i][j + 1] == -1)
						block[i][j]++;
				if (i + 1 < 9 && j - 1 >= 0)
					if (block[i + 1][j - 1] == -1)
						block[i][j]++;
				if (i + 1 < 9)
					if (block[i + 1][j] == -1)
						block[i][j]++;
				if (i + 1 < 9 && j + 1 < 19)
					if (block[i + 1][j + 1] == -1)
						block[i][j]++;
			}//��ź ����

	for (i = 0;i < 9;i++)
		for (j = 0;j < 19;j++) {
			if (block[i][j] == 0) {
				mask[i][j] = 1;
				if (i - 1 >= 0 && j - 1 >= 0)
					mask[i - 1][j - 1] = 1;
				if (i - 1 >= 0)
					mask[i - 1][j] = 1;
				if (i - 1 >= 0 && j + 1 < 19)
					mask[i - 1][j + 1] = 1;
				if (j - 1 >= 0)
					mask[i][j - 1] = 1;
				if (j + 1 < 19)
					mask[i][j + 1] = 1;
				if (i + 1 < 9 && j - 1 >= 0)
					mask[i + 1][j - 1] = 1;
				if (i + 1 < 9)
					mask[i + 1][j] = 1;
				if (i + 1 < 9 && j + 1 < 19)
					mask[i + 1][j + 1] = 1;
			}
		}

	printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	printf("|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F | G | H | I | J |\n");
	printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	for (i = 0;i < 9;i++) {
		printf("| %d |", i + 1);
		for (j = 0;j < 19;j++) {
			if (mask[i][j] == 1) {
				if (block[i][j] != 0)
					printf(" %d ", block[i][j]);
				else if(block[i][j] == 0)
					printf("   ");
			}
			else
				printf(" ? ");
			printf("|");
		}
		printf("\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	}//���

	printf("��� ����� �����? (XY) ");
	scanf("%c%c", &x,&y);
	r = x - '0';
	if (y >= 65)
		w = y - 'A' + 10;
	else
		w = y - '0';

	while (block[r-1][w-1] != -1) {
		mask[r-1][w-1] = 1;

		printf("����� �������ϴ�.\n\n");
		printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
		printf("|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F | G | H | I | J |\n");
		printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
		for (i = 0;i < 9;i++) {
			printf("| %d |", i + 1);
			for (j = 0;j < 19;j++) {
				if (mask[i][j] == 1) {
					if (block[i][j] != 0)
						printf(" %d ", block[i][j]);
					else if (block[i][j] == 0)
						printf("   ");
				}
				else
					printf(" ? ");
				printf("|");
			}
			printf("\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
		}//���
		count = 0;
		for (i = 0;i < 9;i++)
			for (j = 0;j < 19;j++)
				if (mask[i][j] == 1)
					count++;
		if (count == 151) {
			printf("***************WINNER***************\n");
			break;
		}// ���� ���

		printf("��� ����� �����? (XY) ");
		scanf(" %c%c", &x, &y);
		r = x - '0';
		if (y >= 65)
			w = y - 'A' + 10;
		else
			w = y - '0';
	}//���� ����

	if (block[r-1][w-1] == -1)
		printf("��ź�� �������ϴ�. ������ ����Ǿ����ϴ�.\n");
}