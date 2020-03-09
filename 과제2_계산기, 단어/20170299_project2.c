#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str[10] = "";    //입력
	char user_s[10] = "";
	char past_s[10] = "";
	int x, y;

	printf("Words? ");
	gets(str);
	strcpy(past_s, str);

	for(x=0;;x++) {
		printf("Words? ");
		gets(str);

		if (!strcmp(str, "end"))
			break;;

		strcpy(user_s, str);
		
		for (x = 0;x < strlen(past_s);x++) {
			for (y = 0;y < strlen(user_s);y++) {
				if (past_s[x] == user_s[y])
					break;                 //과거를 기준으로 비교
			}
			if (past_s[x] == user_s[y])
				break;
		}
		if (x != strlen(past_s) && y != strlen(user_s)) {
			if (past_s[x] == user_s[y]) {
				for (int i = 0;i < strlen(past_s);i++) {
					if (i == x) {
						printf("(");
						printf("%c", past_s[i]);
						printf(")");
					}
					else printf("%c", past_s[i]);
				}
				printf(" - ");
				for (int i = 0;i < strlen(user_s);i++) {
					if (i == y) {
						printf("(");
						printf("%c", user_s[i]);
						printf(")");
					}
					else printf("%c", user_s[i]);
				}
			}
		}
		else printf("no cross word");

			printf("\n");
		
		strcpy(past_s, user_s);
	}
}