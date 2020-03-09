#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int splitint(char*str, int ret[10]) {
	int i = 0;
	char * tok;

	tok = strtok(str, ",");
	while (tok != NULL) {
		ret [i++] = atoi(tok);
		tok = strtok(NULL, ",");
	}

	return i;

}

int main() {
	char data[50];
	int result[10] = { 0 };
	int i = 0;
	char * tok;
	int count;

	gets(data);
	
	count = splitint(data, result);

	for (i = 0; i < count; i++) {
		printf("%d ", result[i]);
	}

}