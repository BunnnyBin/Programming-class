#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main() {
	FILE * pFile;
	char(*pstr)[100];
	char str[100];  //단어장 1줄 사본
	char comword[1000][6]; //모든 컴퓨터 단어 저장(중복 방지)
	char word[6];   //컴퓨터 단어
	char user[20];  //사용자 입력단어
	char * token;
	int last;
	int n = 0;       //사전파일에 단어가 몇개인지
	int count = 0;   //컴퓨터 단어 몇개 생성한지;
	int i,j;

	pFile = fopen("dict_test.txt", "r");
	if (pFile == NULL) {
		printf("파일이 존재하지 않거나 오류가 났습니다.\n다른 파일 이름을 입력하시오.\n");
		return 0;
	}
	else {
		printf("********************GAME START********************\n");
		while (!feof(pFile)) {
			fgets(str, 100, pFile);
			n++;
		}//사전 단어가 몇개인지
		fclose(pFile);

		pstr = malloc(100 * n);
		pFile = fopen("dict_test.txt", "r");
		i = 0;
		while (!feof(pFile)) {
			fgets(str, 100, pFile);
			strcpy(pstr[i++], str);
		}
		fclose(pFile);

		srand((unsigned)time(NULL));
		while (1) {
			last = rand() % n;
			strcpy(str, pstr[last]);
			token = strtok(str, " : ");
			if (strlen(token) == 5)
				if (strstr(pstr[last], "n.") != NULL) {
					strcpy(word, token);
					strcpy(comword[count], word);
					break;
				}
		}
		printf("컴퓨터의 단어 : %s\n", word);

		printf("당신의 단어는? ");
		gets(user);
		while (strcmp(user, "end")) {
			if (word[4] == user[0]) {
				if (strlen(user) == 5) {
					i = 0;
					while (i != n) {
						strcpy(str, pstr[i]);
						token = strtok(str, " : ");
						if (!strcmp(user, token)) {
							if (strstr(pstr[i], "n.") != NULL) {
								printf("맞았습니다.\n");
								
								last = rand() % n;
								while (1) {
									strcpy(str, pstr[last]);

									if (str[0] == user[4]) {
										token = strtok(str, " : ");
										if (strlen(token) == 5)
											if (strstr(pstr[last], "n.") != NULL) {
												for (j = 0;j <= count;j++) 
													if (!strcmp(comword[j], token)) {
														j = -1;
														break;
													}//중복 검사
												if (j != -1) {
													strcpy(word, token);
													strcpy(comword[++count], word);
													break;
												}//중복이 아니라면
											}
									}
									if (last + 1 < n)
										last++;
									else if(last + 1 >=n)
										last = rand() % n;
								}//컴퓨터 단어 생성
								printf("컴퓨터의 단어 : %s\n", word);
								break; //사용자가 맞았다~!

							} //명사가 맞다
							else {
								printf("명사를 입력하세요.(%s)\n", word);
								break;
							}
						}//사전 단어가 맞다
						i++;
					}//사전+명사인지
					if (i == n)
						printf("사전에 있는 단어를 입력하세요.(%s)\n", word);
				}
				else
					printf("5글자 단어를 입력하세요.(%s)\n", word);
			}
			else
				printf("연결되는 단어를 입력하세요.(%s)\n", word);

			printf("당신의 단어는? ");
			gets(user);
		}//game play

	}//파일 열기 성공
}