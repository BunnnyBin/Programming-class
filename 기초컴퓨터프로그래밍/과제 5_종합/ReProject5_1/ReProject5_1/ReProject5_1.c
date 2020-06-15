#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Generate_Lotto(int number[6]);

int main()
{
	int nth;
	int lotto[6];
	int array[1000][6] = { 0 };
	int i, j;
	int same = 0;

	srand((unsigned)time(NULL));

	printf("�� ���� �ζ� ��ȣ�� �����ұ��? ");
	scanf("%d", &nth);

	for (i = 0;i < nth;i++) {
		Generate_Lotto(lotto);

		for (j = 0;j < i;j++) {
			same = 0;  
			for (int x = 0; x < 6;x++)       
				for (int y = 0;y < 6;y++)
					if (array[j][x] == lotto[y])
						same++;

			if (same == 6) {                  
				Generate_Lotto(lotto);   
				j = 0;                    
			}
		}//j�� for��(lotto ���ڹ迭 �ߺ� �˻�)

		for (j = 0;j < 6;j++)        
			array[i][j] = lotto[j];  

		printf("%3dth Lotto: ", i + 1);

		for (j = 0;j < 6;j++)        
			printf("%d ", lotto[j]);
		printf("\n");

	} //i�� for��
	printf("\n20170299_������\n");
} //main

void Generate_Lotto(int number[6])
{
	static int  nth = 0;  //�� ��° �ζ� ��ȣ�� ����� ������ ���� (main�Լ��� nth�� ���� �ٸ� ����)
	                      //������������ -> Generate_Lotto�Լ��� �ٽ� ���ƿ͵� ī���õǵ���
	int i, j;

		nth++;            //�ζ� ��ȣ�� ����°� �� ��°���� ī��Ʈ

	if (nth == 2) {
		number[0] = 1;
		number[1] = 3;
		number[2] = 13;
		number[3] = 31;
		number[4] = 41;
		number[5] = 45;
		
		return;
	}//2��° �ζǿ�
	else if (nth == 4) {
		number[0] = 13;
		number[1] = 31;
		number[2] = 45;
		number[3] = 41;
		number[4] = 3;
		number[5] = 1;

		return;
	}//4��° �ζ� �迭�� ���� �� 
	else {
		for (i = 0;i < 6;i++) 
			number[i] = rand() % 45 + 1;
	}//�� �� �ζ�

	for (i = 0;i < 6;i++)            //�ζǼ��� �ߺ� ����
			for (j = 0;j < 6;j++) {
				while (number[i] == number[j] && j != i)
					number[i] = rand() % 45 + 1;
			}
	
} //Generate_Lotto