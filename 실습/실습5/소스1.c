#include <stdio.h>

int strlen(char * str) {
	int i = 0;

	while (str[i] != NULL)
		i++;

	return i;
}

int strcmp (char * str1, char * str2) {
	int i = 0;

	while (str1[i] != NULL && str2[i] != NULL) {
		if (str1[i] > str2[i])
			return 1;
		if (str1[i] < str2[i])
			return -1;

		i++;
	}

	return 0;
}

int main() {
	char data1[20] = "Hello";
	char data2[20] = "Hello";

	printf("%d\n", strcmp(data1,data2));
}
