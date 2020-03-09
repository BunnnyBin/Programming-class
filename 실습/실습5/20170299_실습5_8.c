#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char num[30];
	char result[50] = "";
	int i = 0;
	int count = 0; // ,¸¦ ¼¾´Ù
	gets(num);

	while (i != strlen(num)) {
		for (int j = 0; j < 3; j++) {
			result[i + count] = num[strlen(num) - (i + 1)];
		    i++;

			if (i == strlen(num))
				break;
		}
		if (i == strlen(num))
			break;

		result[i + count] = ',';
		count++;
	}

	for (i = strlen(result) - 1; i >= 0; i--)
		printf("%c", result[i]);
	printf("\n");

}