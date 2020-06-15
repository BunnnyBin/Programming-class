#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[30][30] = { 0 };
	int n;

	printf("3 ~ 9사이의 홀수n의 값을 입력하시오: ");
	scanf("%d", &n);
	while (n % 2 == 0 || n < 3 || n > 9) {               //만약 3,5,9 외의 값을 입력하면 다시 입력
		printf("3 ~ 9사이의 홀수n의 값을 입력하시오: ");
		scanf("%d", &n);
	}

	int i=0,j=n/2,x;

	for (x = 1;x <= n * n;x++) {
		if (a[i][j] != 0) {   //이미 숫자가 있다면
			i = (i + 2) % n;
			j = (j - 1 + n) % n;
			a[i][j] = x;
		}

		a[i][j] = x;          //값 넣기
		i = (i - 1 + n) % n;
		j = (j + 1) % n;      //다음 칸으로 이동
	}

	for (i = 0;i < n;i++)     
		for(j=0;j<n;j++) {
			a[i][n] += a[i][j];
			a[n][i] += a[j][i];
	}//총합

	for (i = 0;i <= n;i++) {
		for (j = 0;j <= n;j++) {
			if (i == n && j == n)
				break;
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}//출력

}//main