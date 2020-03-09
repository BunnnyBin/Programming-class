#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char pi[15] = "3.1415926535";
	int point;

	printf("몇 자리까지 출력할까요? ");
	scanf("%d", &point);

	if (pi[2 + point] < 53)
		pi[2 + point] = NULL;
	else if (pi[2 + point] >= 53) {
		pi[1 + point]++;
		pi[2 + point] = NULL;
	}

	printf("%s\n", pi);
}