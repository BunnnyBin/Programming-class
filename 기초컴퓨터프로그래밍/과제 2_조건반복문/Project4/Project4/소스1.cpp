#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAWUI 0
#define BAWUI 1
#define BO 2
int main(void) {
	int round, com, user, com_win = 0, com_lose = 0;  //컴퓨터 이긴것과 컴퓨터 진것 즉, 사용자가 이긴 것과 관련된 변수

	printf("가위바위보 게임\n컴퓨터 : 0승 0패, 당신 : 0승 0패\n\n");

	for (round = 1;(com_win < 3 && com_lose < 3);round++) {  //컴퓨터가 3승하기 전까지 라운드를 카운트
		                                                 //단, 컴퓨터 이긴 것만을 계산하면 사용자가 3승 넘게 이겨도 컴퓨터가 3승할 때까지 계산하므로 컴퓨터가 3승 진것 즉, 사용자가 이긴 것도 계산해야 함
		srand(time(NULL));

		com = rand();
		com %= 3;

		printf("(라운드 %d)\n", round);
		printf("컴퓨터가 결정했습니다.\n");
		printf("무엇을 내시겠습니까? (가위 : 0, 바위 : 1, 보 : 2) ");
		scanf("%d", &user);  //사용자가 가위바위보를 냄

		while (user < 0 || user > 2) {   //사용자가 가위바위보 이외를 입력하는 것을 방지하기 위해
			printf("입력을 잘못하셨습니다. 0, 1, 2 중에 선택하세요. ");
			scanf("%d", &user);
		}


		switch (com) {         //여기서 누가 이겼는지 계산. 컴퓨터가 무엇을 냈는지에 따라 case분류
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
		printf("컴퓨터 : %d승 %d패, 당신 : %d승 %d패\n\n", com_win, com_lose, com_lose, com_win); //결론 도출
	}

	if (com_win == 3) printf("컴퓨터가 이겼습니다\n");
	else printf("당신이 이겼습니다.\n");


	printf("\n20170299 김유빈, 20165389 정다희\n");
}