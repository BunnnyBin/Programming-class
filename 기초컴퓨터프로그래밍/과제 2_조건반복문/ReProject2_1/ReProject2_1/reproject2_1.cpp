#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int low;
	scanf("%d", &low);

	int i, j;
	int x = 1;
	for (i = 0; i < low; i++) {
		for (j = 0; j < low - i;j++)
			printf("    ");

		for (j = low - (i + 1); j <= low - (i + 1) + (i * 2); j++) {
			printf("%3d ", x++);
		}
		printf("\n");
	}
}