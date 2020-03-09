#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last = 0;

void memory(char * str[100]) {
	char input[100];
	int i = last;
	
	gets(input);
	gets(input);  //엔터키 입력 방지
	while (1) {
		if (!strcmp(input, "end"))
			break;

		str[i] = malloc(sizeof(input) + 1);
		if (str[i] == NULL) {
			printf("메모리 확보 실패\n");
			exit(0);
		}
		strcpy(str[i], input);
		i++;
		gets(input);
	}
	last = i;

	int x;
	for (x = 0;x < last;x++)
		printf("%.2d : %s\n", x+1, str[x]);
}

void erase(char*str[100]) {
	int line;
	int x;

	scanf("%d", &line);

	free(str[line - 1]);
	str[line - 1] = NULL;

	for (x = 0;x < last;x++) {
		if (str[x] == NULL)
			printf("%.2d : (deleted)\n", x + 1);
		else printf("%.2d : %s\n", x + 1, str[x]);
	}
}

void arrange(char*str[100]) {
	int x,y;

	for (x = 0;x < last;x++) {
		if (str[x] == NULL) {
			for (y = x;y < last;y++)
				str[y] = str[y + 1];
			str[y] = NULL;  //가장 마지막을 NULL로
			last -= 1;
		}
	}

	for (x = 0;x < last;x++)
		printf("%.2d : %s\n", x + 1, str[x]);
}

int main() {
	char user; //명령어(1,2,3)
	char * ptrstr[100];
	
	while (1) {
		printf("명령 (1:입력, 2:삭제, 3:정리) : ");
		scanf("%d", &user);

		if (user == 1) {
			printf("문장을 입력하새요. 입력이 끝나면 end라고 입력하세요.\n");
			memory(ptrstr);
		}
		else if (user == 2) {
			printf("몇 행을 삭제할까요? ");
			erase(ptrstr);
		}
		else if (user == 3)
			arrange(ptrstr);
	}
}