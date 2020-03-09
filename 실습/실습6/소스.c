#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char input[100];
	char *strptr[100];
	int n = 0;
	
	printf("문장을 입력하시오.\n");
	gets(input);

	while (1) {
		if (!strcmp(input, "end"))
			break;

		strptr[n] = malloc(strlen(input) + 1);
		strcpy(strptr[n], input);
		n++;

		printf("문장을 입력하시오.\n");
		gets(input);
	}

	for (int x = 0; x < n; x++)
		printf("%.3d : %s\n", x + 1, strptr[x]);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          