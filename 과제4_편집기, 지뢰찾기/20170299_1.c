#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last = 0;

void memory(char * str[100]) {
	char input[100];
	int i = last;
	
	gets(input);
	gets(input);  //����Ű �Է� ����
	while (1) {
		if (!strcmp(input, "end"))
			break;

		str[i] = malloc(sizeof(input) + 1);
		if (str[i] == NULL) {
			printf("�޸� Ȯ�� ����\n");
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
			str[y] = NULL;  //���� �������� NULL��
			last -= 1;
		}
	}

	for (x = 0;x < last;x++)
		printf("%.2d : %s\n", x + 1, str[x]);
}

int main() {
	char user; //��ɾ�(1,2,3)
	char * ptrstr[100];
	
	while (1) {
		printf("��� (1:�Է�, 2:����, 3:����) : ");
		scanf("%d", &user);

		if (user == 1) {
			printf("������ �Է��ϻ���. �Է��� ������ end��� �Է��ϼ���.\n");
			memory(ptrstr);
		}
		else if (user == 2) {
			printf("�� ���� �����ұ��? ");
			erase(ptrstr);
		}
		else if (user == 3)
			arrange(ptrstr);
	}
}