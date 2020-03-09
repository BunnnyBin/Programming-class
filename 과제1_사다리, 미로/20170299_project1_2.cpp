#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char ladder[20][5] = { 0 };
	int i, j,x;   //i:����, j: ����
	
	srand((unsigned)time(NULL));
	for (x = 0;x < 20;x++) {
		i = rand() % 20;
		j = rand() % 4;
		
		if (ladder[i][j] == 1) {
				x--;
				continue;
			}//���ٿ��������μ�����

		if (ladder[i][j - 1] == 1) { //�翷�� ���� ���μ� ����
			if (j != 0) {
				x--;
				continue;
			}
		}
		if(ladder[i][j + 1] == 1)
			if (j != 3) {
				x--;
				continue;
			}
			
		ladder[i][j] = 1;  //��� ������ �����ϸ� ���μ� ����
		}//<���μ� ����>

	int wcount;   //�� ���� ���μ� ����
	for (j = 0;j < 4;j++) {
		wcount = 0; 
		for (i = 0;i < 20;i++) 
			if (ladder[i][j] == 1)
				wcount++;

		if(wcount < 3) //�� �ٿ� ���μ� 3�� �̸��϶�
			for (x = 0;x < 2;x++) { //2���� �� �߰�
				i = rand() % 20;

				if (ladder[i][j] == 1) {
					x--;
					continue;
				}//���ٿ��������μ�����

				if (ladder[i][j - 1] == 1) { //�翷�� ���� ���μ� ����
					if (j != 0) {
						x--;
						continue;
					}
				}
				if (ladder[i][j + 1] == 1)
					if (j != 3) {
						x--;
						continue;
					}

				ladder[i][j] = 1;
			}
	}//<�� �ٿ� �ּ� 3���� ������>

	printf("1          2          3          4          5\n");
	for (i = 0;i<20;i++) {
		for (j = 0;j < 4;j++) {
			printf("|");

			if (ladder[i][j] == 0)
				printf("          ");
			else if (ladder[i][j] == 1)
				printf("----------");
		}
		printf("|\n");
	}//<��� ���>
	printf("A          B          C          D          E\n");

	int result;
	for (x = 1;x <= 5;x++) { //x���� = �����ȣ
		i = 0;  //i(������) �ʱ�ȭ
		j = x - 1;

		while (i != 20) {
			if (j == 0) {
				if (ladder[i][j] == 0)
					i++;
				if (ladder[i][j] == 1)
				    i++, j++;
			}
			else if (j == 4) {

				if (ladder[i][j-1] == 0)
					i++;
				if (ladder[i][j-1] == 1)
				    i++,j--;
			}
			else {
				if (ladder[i][j] == 0 && ladder[i][j - 1] == 0)
					i++;
				if (ladder[i][j] == 1)
					j++, i++;
				if (ladder[i][j] == 0 && ladder[i][j - 1] == 1)
					j--, i++;
			}
		}
		printf("%d -> %c\n", x , 'A' + j);
	}//<��ٸ� ��� ���>
	printf("20170299 ������\n");
}