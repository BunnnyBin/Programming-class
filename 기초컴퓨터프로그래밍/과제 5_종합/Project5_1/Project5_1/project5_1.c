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
			same = 0;  //���� same�� 0���� �ʱ�ȭ

			for(int x = 0; x < 6;x++)       //array�迭 j�ٿ� lotto�� ���� ���ڹ迭�� �ִ��� Ȯ��
			   for (int y = 0;y < 6;y++)
				  if (array[j][x] == lotto[y])
					  same++;

			if (same == 6) {              //lotto�� ���� ���ڹ迭�� �̹� �ִٸ�    
				Generate_Lotto(lotto);    //�ٽ� lotto �̱�
				j = 0;                    //���� ���� lotto�� ���� ���� ���ڹ迭�� �־����� Ȯ��( array 0��°�ٺ��� �ٽ� Ȯ��) 
			}
		}//j�� for��(lotto ���ڹ迭 �ߺ� �˻�)

		for (j = 0;j < 6;j++)        //lotto�� ���� �迭��� �ߺ��� �ȵȴٸ�
			array[i][j] = lotto[j];  //array�� ���� ����
           
		printf("%3dth Lotto: ", i + 1);

		for (j = 0;j < 6;j++)        //lotto ���  
			printf("%d ", lotto[j]);
		printf("\n");

	} //i�� for��
	printf("\n20170299_������\n");
} //main

void Generate_Lotto(int number[6])
{
	int i, j;
	
	for (i = 0;i < 6;i++)
		number[i] = rand() % 45 + 1;    //�ζ� �����ϰ� ���� ����

	for (i = 0;i<6;i++)
		for (j = 0;j < 6;j++) {
			while (number[i] == number[j] && j != i)   //���ο� �ߺ��Ǵ� ���� ����
				number[i] = rand() % 45 + 1;
		} 
} //Generate_Lotto