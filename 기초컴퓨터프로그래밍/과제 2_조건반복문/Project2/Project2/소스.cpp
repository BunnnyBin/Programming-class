#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N, M, i, j, gap;

	scanf("%d %d", &N, &M);

	for (j = 1; j < 10; j++) {

		for (i = N; i <= M; i++) {

			for (gap = 0; gap < (80 - 10 * (M - N + 1)) / (M - N + 2); gap++) 
				printf(" ");

			printf("%d * %d = %2d", i, j, i*j);
		}
		printf("\n");
	}

	printf("\n20170299 ±èÀ¯ºó, 20165389 Á¤´ÙÈñ\n");
}