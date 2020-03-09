#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char input[100];
	char * str[5];
	char * temp;
	int i,j;

	for (i = 0; i < 5; i++) {
		gets(input);
		str[i] = malloc(sizeof(input) + 1);
		strcpy(str[i], input);
	}

	for(i=0;i<5;i++)
		for (j = i; j < 5; j++) {
			if (strcmp(str[i], str[j]) == 1) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}

	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%s\n", str[i]);

}