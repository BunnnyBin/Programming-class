#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char str1[20];
	char str2[300] = "";

	int i;

	for (i = 0; i < 10; i++) {
		printf("%d번째 단어는? ", i + 1);
		gets(str1);
		strcat(str1, " ");

		strcat(str2, str1);
	}

	printf("%s\n", str2);
}