#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N, M, row, gap, i, temp = 0;

	printf("N : ");
	scanf("%d", &N);
	printf("M : ");
	scanf("%d", &M);

	while ((N == 3 || N == 4) && M % 2 == 0) {  //N=3,4�� �� M�� ���� Ȧ���� �ƴ� �� �ٽ� �Է¹޵��� �ϴ� ��ġ
		printf("N ���� 3�̳� 4�� ��쿡�� M ���� Ȧ���� �����մϴ�. M ���� �ٽ� �Է��ϼ���.\n");
		printf("M : ");
		scanf("%d", &M);
	}



	switch (N)
	{
	case 1: for (row = 1; row <= M; row++) {   //'��'�� ���� ������ ������ ��ĭ�� ����

		for (gap = 0; gap < M - row; gap++)    //���� ��� M=4�� ��, ù° �� ��ĭ�� 3ĭ,��° �� ��ĭ 2ĭ,��° �� ��ĭ 1ĭ, ��° �� ��ĭ 0ĭ�̴�. 
			printf(" ");                       //�̶� ��ĭ ��Ģ�� �߰��Ͽ� �� ���� M-row���� ��ĭ�� ���� 

		for (i = 1; i <= row; i++)             //ù° �ٿ� ����1, ��° �ٿ� ���� 2,3, ��° �ٿ� ���� 4,5,6, ... �� ���
			printf("%3d", i + temp);           //�̶� %3d�� �� ������ M���� Ŀ������ ���ڰ� ��ġ�� �ʰ� �ϱ� ���ؼ�

		temp += row;     //���� �ٷ� �Ѿ�� �ٽ� ����1�� ���ư��� �ʰ� �״�� 1�� ���������� �ϴ� ��ġ (���� temp)

		printf("\n");    //ù° �ٿ� ����1��, ��° �ٿ� ����2��...������ �ٿ� ���� ������ ������ ������
		}
			break;


	case 2: for (row = M; row > 0; row--) {     //N=1�� ���� �ݴ�� ����� ���� row�� M���� �����Ͽ� 1���� �ٿ��� ����
		                                        //�������� N=1�� ���� ����
		for (gap = 0; gap < M - row; gap++)   
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }
			break;
			

	case 3: for (row = 1; row <= M / 2 + 1; row++) {   //���̾Ƹ��� N=1�� N=2�� ��ħ
		                                               //���� N=1�� ���� ���. ��, ���⼭ ��Ģ�� �߰��Ͽ� M/2+1�� �ٱ����� ���. 
		for (gap = 0; gap < M / 2 + 1 - row; gap++)
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }

			for (row = M / 2; row > 0; row--) {     //N=2�� ���� ���. �̶��� M/2���� �ٸ� ���. M/2���� 1���� ���� ���

				for (gap = 0; gap <= M / 2 - row; gap++)
					printf(" ");

				for (i = 1; i <= row; i++)          
					printf("%3d", i + temp);        //temp������ ���� N=1�϶��� ���� �״�� �̾� �����Ƿ� ���ڴ� ��� ������
				 
				temp += row;

				printf("\n");
			}
			break;


	case 4: for (row = M / 2 + 1; row > 0; row--) {     //���ﰢ���� N=2�� N=1�� ��ħ
		                                                //N=3�϶��� ����ϰ� N=2�� ���� ����ϴµ� M/2+1���� 1���� ���� ����
		for (gap = 0; gap <= M / 2 + 1 - row; gap++)
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }

			for (row = 2; row <= M / 2 + 1; row++) {    //N=1�� ���. ���� ���� �𷡽ð迡 ��� ���ڴ� �̹� N=2�϶� ����ؼ�
				                                        //row=2���� ����
				for (gap = 0; gap < M / 2 + 1 - row; gap++)
					printf(" ");

				for (i = 1; i <= row; i++)
					printf("%3d", i + temp);

				temp += row;

				printf("\n");
			}
	
	}


	printf("\n20170299 ������, 20165389 ������\n");
}