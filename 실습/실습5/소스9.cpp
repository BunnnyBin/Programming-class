#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void inttostr(char *in, char *result) {
	char num[10][3] = { "","��","��","��","��","��","��","ĥ","��","��" };
	char unit[4][5] = { "","��","��","õ" };
	char buf[15];
	int i;

	strcpy(result, "");  //�ʱ�ȭ

	for (i = 0; i < strlen(in); i++) {
		if (i == 0 && in[i] == '1')  ;
		else 
		    strcat(result, num[in[i] - '0']); 
		strcat(result, unit[strlen(in) - i - 1]);
	}
	
	return;
}

int main() {
	char unit[10][5] = { "","��","��","��","��"};
	char user[15];
	char result[100];
	char in[5] = "";
	int len;
	int i,j;
	int count = 0;

	printf("���ڸ� �Է��Ͻÿ�. \n");
	gets_s(user,sizeof(user));
	len = strlen(user);

	for (i = len / 4; i >= 0; i--) {
		strcpy(in, "");

		if (i == len / 4)
			for (j = 0; j < len % 4; j++) {
				in[j] = user[j];
				count += (j+1);
			}
		else 
			for (j = 0; j < 4; j++) {
				in[j] = user[count++];
			}

		inttostr(in,result);   //õ�����
		strcat(result, unit[i]);  // ��/��/��/��
	}
	printf("%s\n", result);
}