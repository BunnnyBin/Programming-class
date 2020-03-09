#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct PLAYER {
	int money;
	int site;
};

struct CITY {
	int owner;
	char owner_sign[5];
	char nowwho1_sign[5];
	char nowwho2_sign[5];
	char name[10];
};

int main() {
	struct PLAYER player1 = { 5000,0 };
	struct PLAYER player2 = { 5000,0 };
	struct CITY city[11] = { { 0,"","","" ,"Start"},
	                         { 0,"","","" ,"Tokyo" },
	                         { 0,"","","" ,"Sydney" },
	                         { 0,"","","" ,"LA" },
	                         { 0,"","","" ,"Paris" },
	                         { 0,"","","" ,"Chicago" },
	                         { 0,"","","" ,"Phuket" },
	                         { 0,"","","" ,"New Delhi" },
	                         { 0,"","","" ,"Hanoi" },
	                         { 0,"","","" ,"Beijing" },
	                         { 0,"","","" ,"Seoul" } 
	};
	int turn = 1;
	int dice;

	printf("마블게임을 시작하겠습니다.\n");
	while (turn <= 30) {
		printf("\n<<<<<<<<<<<<TURN %d>>>>>>>>>>>>>\n", turn);
		strcpy(city[player1.site].nowwho1_sign, "");
		strcpy(city[player2.site].nowwho1_sign, "");
		strcpy(city[player2.site].nowwho2_sign, ""); //초기화
		
		dice = rand() % 6 + 1; //주사위
		player1.site += dice;
		player1.site = player1.site % 11;  //현재위치
		strcpy(city[player1.site].nowwho1_sign,"(1)");  //현재위치출력
		printf("player1 got %d\n", dice);

		if (player1.site != 0) { //start제외
			if (city[player1.site].owner == 0) {  //주인없는땅
				printf("%s(empty)\n", city[player1.site].name);
				if (player1.money >= 300) { //돈이 있다
					player1.money -= 300;
					city[player1.site].owner = 1;
					strcpy(city[player1.site].owner_sign, "(1)");
					printf("player1 buys %s\n", city[player1.site].name);
				}
				else if (player1.money < 300)  //돈이 부족
					printf("can't buy %s", city[player1.site].name);
			}
			else if (city[player1.site].owner == 2) { //남의 땅
				printf("%s%s\n", city[player1.site].name, city[player1.site].owner_sign);
				player1.money -= 600;
				player2.money += 600;
			}
			else if (city[player1.site].owner == 1) //자기 땅
				printf("%s%s\n", city[player1.site].name, city[player1.site].owner_sign);
		}
		
		else printf("*Start*\n");
		printf("player1's balance is %d\n", player1.money);

		printf("|------------|   |------------|   |------------|   |------------|\n");
		printf("| Chicago%3s |   | Phuket%3s  |   |New Delhi%3s|   |  Hanoi %3s |\n",city[5].owner_sign, city[6].owner_sign, city[7].owner_sign, city[8].owner_sign);
		printf("|   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |\n",city[5].nowwho1_sign,city[5].nowwho2_sign, city[6].nowwho1_sign, city[6].nowwho2_sign, city[7].nowwho1_sign, city[7].nowwho2_sign, city[8].nowwho1_sign, city[8].nowwho2_sign);
		printf("|____________|   |____________|   |____________|   |____________|\n");
		printf("                                                   |------------|\n");
		printf("                                                   |  Beijing%3s|\n",city[9].owner_sign);
		printf("|------------|                                     |    %3s %3s |\n",city[9].nowwho1_sign, city[9].nowwho2_sign);
		printf("|   Paris%3s |                                     |____________|\n",city[4].owner_sign);
		printf("|   %3s %3s  |                                     |------------|\n",city[4].nowwho1_sign, city[4].nowwho2_sign);
		printf("|____________|                                     |   Seoul%3s |\n",city[10].owner_sign);
		printf("      ^                                            |    %3s %3s |\n",city[10].nowwho1_sign,city[10].nowwho2_sign);
		printf("      |                                            |____________|\n");
		printf("|------------|   |------------|   |------------|   |------------|\n");
		printf("|    LA%3s   |   |  Sydney%3s |   |   Tokyo%3s |   |   *START*  |\n",city[3].owner_sign, city[2].owner_sign, city[1].owner_sign);
		printf("|   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |\n",city[3].nowwho1_sign,city[3].nowwho2_sign, city[2].nowwho1_sign, city[2].nowwho2_sign, city[1].nowwho1_sign, city[1].nowwho2_sign, city[0].nowwho1_sign, city[0].nowwho2_sign);
		printf("|____________|   |____________|   |____________|   |____________|\n\n");
		Sleep(1000);

		if (city[player1.site].owner == 2)
			if (player1.money < 0) {
				printf("!!GAME OVER!!\winner is player2!!\n");
				break; //게임종료
			}

		dice = rand() % 6 + 1;  //주사위
		player2.site += dice;
		player2.site = player2.site % 11;  
		printf("player2 got %d\n", dice);

		if(player1.site == player2.site)
		     strcpy(city[player2.site].nowwho2_sign, "(2)");
		else strcpy(city[player2.site].nowwho1_sign, "(2)");

		if (player2.site != 0) {
			if (city[player2.site].owner == 0) {  //주인없는땅
				printf("%s(empty)\n", city[player2.site].name);
				if (player2.money >= 300) {
					player2.money -= 300;
					city[player2.site].owner = 2;
					strcpy(city[player2.site].owner_sign, "(2)");
					printf("player2 buys %s\n", city[player2.site].name);
				}
				else if (player2.money < 300)
					printf("can't buy %s", city[player2.site].name);
			}
			else if (city[player2.site].owner == 1) { //남의 땅
				printf("%s%s\n", city[player2.site].name, city[player2.site].owner_sign);
				player2.money -= 600;
				player1.money += 600;
			}
			else if (city[player2.site].owner == 2)  //자기 땅
				printf("%s%s\n", city[player2.site].name, city[player2.site].owner_sign);
		}

		else printf("*Start*\n");
		printf("player2's balance is %d\n", player2.money);

		printf("|------------|   |------------|   |------------|   |------------|\n");
		printf("| Chicago%3s |   | Phuket%3s  |   |New Delhi%3s|   |  Hanoi %3s |\n", city[5].owner_sign, city[6].owner_sign, city[7].owner_sign, city[8].owner_sign);
		printf("|   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |\n", city[5].nowwho1_sign, city[5].nowwho2_sign, city[6].nowwho1_sign, city[6].nowwho2_sign, city[7].nowwho1_sign, city[7].nowwho2_sign, city[8].nowwho1_sign, city[8].nowwho2_sign);
		printf("|____________|   |____________|   |____________|   |____________|\n");
		printf("                                                   |------------|\n");
		printf("                                                   |  Beijing%3s|\n", city[9].owner_sign);
		printf("|------------|                                     |    %3s %3s |\n", city[9].nowwho1_sign, city[9].nowwho2_sign);
		printf("|   Paris%3s |                                     |____________|\n", city[4].owner_sign);
		printf("|   %3s %3s  |                                     |------------|\n", city[4].nowwho1_sign, city[4].nowwho2_sign);
		printf("|____________|                                     |   Seoul%3s |\n", city[10].owner_sign);
		printf("      ^                                            |    %3s %3s |\n", city[10].nowwho1_sign, city[10].nowwho2_sign);
		printf("      |                                            |____________|\n");
		printf("|------------|   |------------|   |------------|   |------------|\n");
		printf("|    LA%3s   |   |  Sydney%3s |   |   Tokyo%3s |   |   *START*  |\n", city[3].owner_sign, city[2].owner_sign, city[1].owner_sign);
		printf("|   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |   |   %3s %3s  |\n", city[3].nowwho1_sign, city[3].nowwho2_sign, city[2].nowwho1_sign, city[2].nowwho2_sign, city[1].nowwho1_sign, city[1].nowwho2_sign, city[0].nowwho1_sign, city[0].nowwho2_sign);
		printf("|____________|   |____________|   |____________|   |____________|\n\n");
		Sleep(1000);

		if (city[player2.site].owner == 1)
			if (player2.money < 0) {
				printf("!!GAME OVER!!\winner is player1!!\n");
				break; //게임종료
			}

		turn++;
	}//while

	if (turn == 31) {
		printf("!!GAME OVER!!\n");

		if (player1.money > player2.money)
			printf("winner is player1!!\n");
		else if (player1.money < player2.money)
			printf("winner is player2!!\n");
		else if (player1.money == player2.money)
			printf("무승부!!\n");
	}
}