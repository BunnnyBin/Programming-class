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
		array[i][0] = i + 1;         //��ȣ
		array[i][1] = rand() % 101;  //����
	}

	for (i = 0;i < 30;i++) {
		array[i][2] = 1;
		for (j = 0;j < 30;j++)
			if (array[i][1] < array[j][1])
				array[i][2]++;
	}//���
	
	printf("��ȣ��\n");
	for (i = 0;i < 30;i++)
		printf("%2d�� %3d�� %2d��\n", array[i][0], array[i][1], array[i][2]);
		
	for(i=0;i<30;i++)                        //���������� �迭�� �ٲ�
		for (j = i;j < 30;j++) {
			if (array[i][1] < array[j][1])
				for (int k = 0;k<3;k++) {
					temp = array[i][k];
					array[i][k] = array[j][k];
					array[j][k] = temp;
				}
		}

	printf("������\n");
	for (i = 0;i < 30;i++)
		printf("%2d�� %3d�� %2d��\n", array[i][2], array[i][1], array[i][0]);

}