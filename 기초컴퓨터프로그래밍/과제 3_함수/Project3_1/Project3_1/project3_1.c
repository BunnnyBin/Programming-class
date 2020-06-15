#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int main()
{
	int round, com1, com2, user, score, final_score, high_score = 0;
	clock_t start, end;
	double second;

	for (round = 1; ;round++) {        //①	라운드 구분

		final_score = 0;                //각 라운드 최종점수 초기화

		printf("<라운드%d>\n", round);    //(몇 라운드인지 표시)

		printf("구구단을 외자. 답을 문제 출력 후 3초 이내에 입력하세요.\n준비하세요.\n");
		Sleep(1000);
		printf("3초전\n");
		Sleep(1000);
		printf("2초전\n");
		Sleep(1000);
		printf("1초전\n");
		Sleep(1000);
		printf("START~!\n");
		
		int i;                           //문제의 번수
		for (i = 1; i <= 10; i++) {      //각 문제마다

			srand(time(NULL));

			com1 = rand() % 9 + 1;   // ② 컴퓨터 문제 랜덤
			com2 = rand() % 9 + 1;

			printf("%d) %d * %d = ", i, com1, com2);
			start = clock();     //문제 푸는 시간 시작점

			scanf("%d", &user); 
			end = clock();       //문제 푸는 시간 끝점

			second = (end - start) / 1000.0;     // ③ 시간 계산
			score = 3000 - (end - start);     //④	점수 계산
		

			if (second < 3.000)                //⑤	컴퓨터 vs 사용자 (누가 이겼는지)
				if (user == com1 * com2) {         //정답을 맞췄을 때!

					final_score += score;        //⑥	총점 계산 (여태까지 맞춘 점수 계산)
					printf("(맞았습니다.) %.3f초 소요 : SCORE = %d\n\n", second, final_score);

				}
				else                             // 정답이 틀렸을 때!
					printf("\n(틀렸습니다.) %.3f초 소요 : SCORE = %d\n\n", second, final_score);
				

			else if (second >= 3.000)       //시간을 오버했을 때!
				printf("(제한시간이 지났습니다.) %.3f초 소요 : SCORE = %d\n\n", second, final_score);
			


		}  //문제 for문 맞침



		printf("라운드%d의 최종 점수 = %d\n\n", round, final_score);   //이번 라운드의 최종 점수

		if (high_score < final_score) {                                //⑦	게임은 계속 진행되며 최고 점수 갱신
			high_score = final_score;
			printf("축하합니다! 이번 라운드는 최고 기록을 갱신하셨습니다!\n");
		}
	
		printf("--------------------------------------------------------\n");       //(라운드 마다 구분선)

	}  //라운드 for문 맞침

}