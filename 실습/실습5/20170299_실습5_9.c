#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void inttostr(char *in, char *result) {
	char num[10][3] = { "","일","이","삼","사","오","육","칠","팔","구" };
	char unit[4][5] = { "","십","백","천" };
	char buf[15];
	int i;

	for (i = 0; i < strlen(in); i++) {
		if (strlen(in) != 1&&in[i] == '1');   //맨처음 '일'은 출력
		else
			strcat(result, num[in[i] - '0']);

		if(in[i] - '0' != 0)
		    strcat(result, unit[strlen(in) - i - 1]);
	}

	return;
}

int main() {
	char unit[6][5] = { "","만","억","조","경" };
	char user[15];
	char result[100] = "";
	char in[5] = "";
	int len;
	int i, j;
	int count = 0;
	int start,end; //만억조경 - 4자리씩 끊는점

	printf("숫자를 입력하시오. \n");
	gets_s(user, sizeof(user));
	len = strlen(user);

	if (len % 4 == 0) {
		start = len / 4 - 1;
		end = 4;
	}
	else if (len % 4 != 0) {
		start = len / 4;
		end = len % 4;
	}
	
	for (i = start; i >= 0; i--) {
		strcpy(in, "");

		if(i == start) 
			for (j = 0; j < end; j++) 
				in[j] = user[count++];
		
		else 
			for (j = 0; j < 4; j++) 
				in[j] = user[count++];
				
		inttostr(in, result);   //천백십일
		strcat(result, unit[i]);  // 만/억/조/경

		if (i == 0 && in[3] == '1')
			strcat(result, "일");  //맨 마지막 자리 '일'은 출력
	}

	printf("%s\n", result);
}