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

	for (i = 0; i < strlen(in); i++) {
		if (strlen(in) != 1&&in[i] == '1');   //��ó�� '��'�� ���
		else
			strcat(result, num[in[i] - '0']);

		if(in[i] - '0' != 0)
		    strcat(result, unit[strlen(in) - i - 1]);
	}

	return;
}

int main() {
	char unit[6][5] = { "","��","��","��","��" };
	char user[15];
	char result[100] = "";
	char in[5] = "";
	int len;
	int i, j;
	int count = 0;
	int start,end; //�������� - 4�ڸ��� ������

	printf("���ڸ� �Է��Ͻÿ�. \n");
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
				
		inttostr(in, result);   //õ�����
		strcat(result, unit[i]);  // ��/��/��/��

		if (i == 0 && in[3] == '1')
			strcat(result, "��");  //�� ������ �ڸ� '��'�� ���
	}

	printf("%s\n", result);
}