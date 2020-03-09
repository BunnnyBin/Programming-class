#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char str1[50];
	char str2[50];
	char word[10];
	char change[10];
	char * f, *p;

	printf("문장을 입력하세요 : ");
	gets(str1);
	strcpy(str2, str1);
	printf("찾을 단어는? ");
	gets(word);
	printf("바꿀 단어는? ");
	gets(change);

	f = strstr(str2, word);
	strcpy(f, change);

	p = strstr(str1, word);
	strcat(str2, p + strlen(word));

	printf("결과 : %s", str2);

}