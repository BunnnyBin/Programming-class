#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char str1[50];
	char str2[50];

	printf("끝말잇기를 시작합니다. 첫 단어는 ");
	gets(str1);
	printf("단어는? ");
	gets(str2);
	while (strcmp(str2,"end") != 0) {
	
		printf("%c ", str1[strlen(str1) - 1]);
		printf("%c\n", str2[0]);
		if (str1[strlen(str1) - 1] != str2[0]) 
			printf("이어지지 않습니다. 다시 하세요. ");
		
		else if (str1[strlen(str1) - 1] == str2[0]) {
			printf("correct. word is %s\n", str2);
			strcpy(str1, str2);
		}

		printf("단어는? ");
		gets(str2);
	}
}
