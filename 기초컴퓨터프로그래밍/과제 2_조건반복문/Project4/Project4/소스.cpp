#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAWUI 0
#define BAWUI 1
#define BO 2
int main(void){
	int round, com, user, com_win = 0, com_lose = 0;

	printf("가위바위보 게임\n컴퓨터 : 0승 0패, 당신 : 0승 0패\n\n");

	for (round = 1;(com_win < 3 && com_lose < 3);round++) {
		srand(time(NULL));

		com = rand();
		com %= 3;

		printf("(라운드 %d)\n", round);
		printf("컴퓨터가 결정했습니다.\n");
		printf("무엇을 내시겠습니까? (가위 : 0, 바위 : 1, 보 : 2) ");
		scanf("%d", &user);

		while (user < 0 || user > 2) {
			printf("입력을 잘못하셨습니다. 0, 1, 2 중에 선택하세요. ");
			scanf("%d", &user);
		}

		switch (com) {
		case GAWUI: if (user == BAWUI) {
						printf("컴퓨터는 가위, 당신은 바위, 당신이 이겼습니다.\n");
						com_lose++;
					}
					else if (user == BO) {
						printf("컴퓨터는 가위, 당신은 보, 컴퓨터가 이겼습니다.\n");
						com_win++;
					}
					else printf("컴퓨터도 가위, 당신도 가위, 비겼습니다.\n");
					break;

		case BAWUI: if (user == BO) {
						printf("컴퓨터는 바위, 당신은 보, 당신이 이겼습니다.\n");
						com_lose++;
					}
					else if (user == GAWUI) {
						printf("컴퓨터는 바위, 당신은 가위, 컴퓨터가 이겼습니다.\n");
						com_win++;
					}
					else printf("컴퓨터도 바위, 당신도 바위, 비겼습니다.\n");
					break;

		case BO: if (user == GAWUI) {
					printf("컴퓨터는 보, 당신은 가위, 당신이 이겼습니다.\n");
					com_lose++;
				 }
				 else if (user == BAWUI) {
					 printf("컴퓨터는 보, 당신은 바위, 컴퓨터가 이겼습니다.\n");
					 com_win++;
				 }
				 else printf("컴퓨터도 보, 당신도 보, 비겼습니다.\n");
				 break;
		}
		printf("컴퓨터 : %d승 %d패, 당신 : %d승 %d패\n\n", com_win, com_lose, com_lose, com_win);
	}
	if (com_win == 3) printf("컴퓨터가 이겼습니다\n");
	else printf("당신이 이겼습니다.\n");
}