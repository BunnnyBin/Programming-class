#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main()
{
	int round, com1, com2, user, score, final_score, high_score = 0;
	clock_t start, end;
	double second;

	for (round = 1; ;round++) {        //��	���� ����

		final_score = 0;                //�� ���� �������� �ʱ�ȭ

		printf("<����%d>\n", round);    //(�� �������� ǥ��)

		printf("�������� ����. ���� ���� ��� �� 3�� �̳��� �Է��ϼ���.\n�غ��ϼ���.\n");
		Sleep(1000);
		printf("3����\n");
		Sleep(1000);
		printf("2����\n");
		Sleep(1000);
		printf("1����\n");
		Sleep(1000);
		printf("START~!\n");
		
		int i;                           //������ ����
		for (i = 1; i <= 10; i++) {      //�� ��������

			srand(time(NULL));

			com1 = rand() % 9 + 1;   // �� ��ǻ�� ���� ����
			com2 = rand() % 9 + 1;

			printf("%d) %d * %d = ", i, com1, com2);
			start = clock();     //���� Ǫ�� �ð� ������

			scanf("%d", &user); 
			end = clock();       //���� Ǫ�� �ð� ����

			second = (end - start) / 1000.0;     // �� �ð� ���
			score = 3000 - (end - start);     //��	���� ���
		

			if (second < 3.000)                //��	��ǻ�� vs ����� (���� �̰����)
				if (user == com1 * com2) {         //������ ������ ��!

					final_score += score;        //��	���� ��� (���±��� ���� ���� ���)
					printf("(�¾ҽ��ϴ�.) %.3f�� �ҿ� : SCORE = %d\n\n", second, final_score);

				}
				else                             // ������ Ʋ���� ��!
					printf("\n(Ʋ�Ƚ��ϴ�.) %.3f�� �ҿ� : SCORE = %d\n\n", second, final_score);
				

			else if (second >= 3.000)       //�ð��� �������� ��!
				printf("(���ѽð��� �������ϴ�.) %.3f�� �ҿ� : SCORE = %d\n\n", second, final_score);
			


		}  //���� for�� ��ħ



		printf("����%d�� ���� ���� = %d\n\n", round, final_score);   //�̹� ������ ���� ����

		if (high_score < final_score) {                                //��	������ ��� ����Ǹ� �ְ� ���� ����
			high_score = final_score;
			printf("�����մϴ�! �̹� ����� �ְ� ����� �����ϼ̽��ϴ�!\n");
		}
	
		printf("--------------------------------------------------------\n");       //(���� ���� ���м�)

	}  //���� for�� ��ħ

}