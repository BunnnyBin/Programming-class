#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char str1[50];
	char str2[50];

	printf("�����ձ⸦ �����մϴ�. ù �ܾ�� ");
	gets(str1);
	printf("�ܾ��? ");
	gets(str2);
	while (strcmp(str2,"end") != 0) {
	
		printf("%c ", str1[strlen(str1) - 1]);
		printf("%c\n", str2[0]);
		if (str1[strlen(str1) - 1] != str2[0]) 
			printf("�̾����� �ʽ��ϴ�. �ٽ� �ϼ���. ");
		
		else if (str1[strlen(str1) - 1] == str2[0]) {
			printf("correct. word is %s\n", str2);
			strcpy(str1, str2);
		}

		printf("�ܾ��? ");
		gets(str2);
	}
}
