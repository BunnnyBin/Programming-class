#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct STR {
	int allocsize;
	char * ptr;
};

int main() {
	struct STR str[3];
	char input[50];
	int i;

	str[0].ptr = malloc(5);
	str[0].allocsize = 5;
	strcpy(str[0].ptr, "nice");
	str[1].ptr = malloc(6);
	str[1].allocsize = 6;
	strcpy(str[1].ptr, "hello");
	str[2].ptr = malloc(3);
	str[2].allocsize = 3;
	strcpy(str[2].ptr, "to");

	for (i = 0; i < 3; i++) {
		gets(input);

		if (strlen(input) + 1 > str[i].allocsize) {
			str[i].ptr = realloc(str[i].ptr, strlen(input) + 1);
			strcpy(str[i].ptr, input);
			str[i].allocsize = strlen(input) + 1;
		}

		else 
			strcpy(str[i].ptr, input);

	}

	printf("allocsize ->\n");
	for (i = 0; i < 3; i++)
		printf("%4d         %s\n",str[i].allocsize,str[i].ptr);
	
	
}