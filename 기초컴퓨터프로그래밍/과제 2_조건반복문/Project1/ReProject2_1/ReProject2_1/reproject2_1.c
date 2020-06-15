#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[50][50] = { 0 };
	int n, low;
	int i, j,x;

	printf("n(단계)를 입력하시오 ");
	scanf("%d", &n);
	printf("몇줄하실지 입력하시오. ");
	
	if (n == 1) {
		x = 1;
		for (i = 0;i < low;i++) 
			for (j = low - (i + 1);j <= low - (i + 1) + (i*2);j++) {
					a[i][j] = x;
					x++;
			}
	}
	if (n == 2) {
		x = 1;
	

	}

	for (i = 0;i < 40;i++) {
		for (j = 0;j < 40;j++) {
			if (a[i][j] == 0)
				printf("    ");
			else printf("%3d ", a[i][j]);
		}
		printf("\n");
	}//출력
}//main