#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main() {
	FILE * pFile;
	char(*pstr)[100];
	char str[100];  //�ܾ��� 1�� �纻
	char comword[1000][6]; //��� ��ǻ�� �ܾ� ����(�ߺ� ����)
	char word[6];   //��ǻ�� �ܾ�
	char user[20];  //����� �Է´ܾ�
	char * token;
	int last;
	int n = 0;       //�������Ͽ� �ܾ �����
	int count = 0;   //��ǻ�� �ܾ� � ��������;
	int i,j;

	pFile = fopen("dict_test.txt", "r");
	if (pFile == NULL) {
		printf("������ �������� �ʰų� ������ �����ϴ�.\n�ٸ� ���� �̸��� �Է��Ͻÿ�.\n");
		return 0;
	}
	else {
		printf("********************GAME START********************\n");
		while (!feof(pFile)) {
			fgets(str, 100, pFile);
			n++;
		}//���� �ܾ �����
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
		printf("��ǻ���� �ܾ� : %s\n", word);

		printf("����� �ܾ��? ");
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
								printf("�¾ҽ��ϴ�.\n");
								
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
													}//�ߺ� �˻�
												if (j != -1) {
													strcpy(word, token);
													strcpy(comword[++count], word);
													break;
												}//�ߺ��� �ƴ϶��
											}
									}
									if (last + 1 < n)
										last++;
									else if(last + 1 >=n)
										last = rand() % n;
								}//��ǻ�� �ܾ� ����
								printf("��ǻ���� �ܾ� : %s\n", word);
								break; //����ڰ� �¾Ҵ�~!

							} //��簡 �´�
							else {
								printf("��縦 �Է��ϼ���.(%s)\n", word);
								break;
							}
						}//���� �ܾ �´�
						i++;
					}//����+�������
					if (i == n)
						printf("������ �ִ� �ܾ �Է��ϼ���.(%s)\n", word);
				}
				else
					printf("5���� �ܾ �Է��ϼ���.(%s)\n", word);
			}
			else
				printf("����Ǵ� �ܾ �Է��ϼ���.(%s)\n", word);

			printf("����� �ܾ��? ");
			gets(user);
		}//game play

	}//���� ���� ����
}