#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAWUI 0
#define BAWUI 1
#define BO 2
int main(void){
	int round, com, user, com_win = 0, com_lose = 0;

	printf("���������� ����\n��ǻ�� : 0�� 0��, ��� : 0�� 0��\n\n");

	for (round = 1;(com_win < 3 && com_lose < 3);round++) {
		srand(time(NULL));

		com = rand();
		com %= 3;

		printf("(���� %d)\n", round);
		printf("��ǻ�Ͱ� �����߽��ϴ�.\n");
		printf("������ ���ðڽ��ϱ�? (���� : 0, ���� : 1, �� : 2) ");
		scanf("%d", &user);

		while (user < 0 || user > 2) {
			printf("�Է��� �߸��ϼ̽��ϴ�. 0, 1, 2 �߿� �����ϼ���. ");
			scanf("%d", &user);
		}

		switch (com) {
		case GAWUI: if (user == BAWUI) {
						printf("��ǻ�ʹ� ����, ����� ����, ����� �̰���ϴ�.\n");
						com_lose++;
					}
					else if (user == BO) {
						printf("��ǻ�ʹ� ����, ����� ��, ��ǻ�Ͱ� �̰���ϴ�.\n");
						com_win++;
					}
					else printf("��ǻ�͵� ����, ��ŵ� ����, �����ϴ�.\n");
					break;

		case BAWUI: if (user == BO) {
						printf("��ǻ�ʹ� ����, ����� ��, ����� �̰���ϴ�.\n");
						com_lose++;
					}
					else if (user == GAWUI) {
						printf("��ǻ�ʹ� ����, ����� ����, ��ǻ�Ͱ� �̰���ϴ�.\n");
						com_win++;
					}
					else printf("��ǻ�͵� ����, ��ŵ� ����, �����ϴ�.\n");
					break;

		case BO: if (user == GAWUI) {
					printf("��ǻ�ʹ� ��, ����� ����, ����� �̰���ϴ�.\n");
					com_lose++;
				 }
				 else if (user == BAWUI) {
					 printf("��ǻ�ʹ� ��, ����� ����, ��ǻ�Ͱ� �̰���ϴ�.\n");
					 com_win++;
				 }
				 else printf("��ǻ�͵� ��, ��ŵ� ��, �����ϴ�.\n");
				 break;
		}
		printf("��ǻ�� : %d�� %d��, ��� : %d�� %d��\n\n", com_win, com_lose, com_lose, com_win);
	}
	if (com_win == 3) printf("��ǻ�Ͱ� �̰���ϴ�\n");
	else printf("����� �̰���ϴ�.\n");
}