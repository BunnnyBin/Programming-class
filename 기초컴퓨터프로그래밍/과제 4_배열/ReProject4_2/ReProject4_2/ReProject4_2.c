#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[30][30] = { 0 };
	int n;

	printf("3 ~ 9������ Ȧ��n�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	while (n % 2 == 0 || n < 3 || n > 9) {               //���� 3,5,9 ���� ���� �Է��ϸ� �ٽ� �Է�
		printf("3 ~ 9������ Ȧ��n�� ���� �Է��Ͻÿ�: ");
		scanf("%d", &n);
	}

	int i=0,j=n/2,x;

	for (x = 1;x <= n * n;x++) {
		if (a[i][j] != 0) {   //�̹� ���ڰ� �ִٸ�
			i = (i + 2) % n;
			j = (j - 1 + n) % n;
			a[i][j] = x;
		}

		a[i][j] = x;          //�� �ֱ�
		i = (i - 1 + n) % n;
		j = (j + 1) % n;      //���� ĭ���� �̵�
	}

	for (i = 0;i < n;i++)     
		for(j=0;j<n;j++) {
			a[i][n] += a[i][j];
			a[n][i] += a[j][i];
	}//����

	for (i = 0;i <= n;i++) {
		for (j = 0;j <= n;j++) {
			if (i == n && j == n)
				break;
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}//���

}//main