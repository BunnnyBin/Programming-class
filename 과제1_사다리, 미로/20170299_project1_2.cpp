#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char ladder[20][5] = { 0 };
	int i, j,x;   //i:가로, j: 세로
	
	srand((unsigned)time(NULL));
	for (x = 0;x < 20;x++) {
		i = rand() % 20;
		j = rand() % 4;
		
		if (ladder[i][j] == 1) {
				x--;
				continue;
			}//한줄에같은가로선방지

		if (ladder[i][j - 1] == 1) { //양옆에 같은 가로선 방지
			if (j != 0) {
				x--;
				continue;
			}
		}
		if(ladder[i][j + 1] == 1)
			if (j != 3) {
				x--;
				continue;
			}
			
		ladder[i][j] = 1;  //모든 조건을 만족하면 가로선 생성
		}//<가로선 생성>

	int wcount;   //각 줄의 가로선 개수
	for (j = 0;j < 4;j++) {
		wcount = 0; 
		for (i = 0;i < 20;i++) 
			if (ladder[i][j] == 1)
				wcount++;

		if(wcount < 3) //한 줄에 가로선 3개 미만일때
			for (x = 0;x < 2;x++) { //2개를 더 추가
				i = rand() % 20;

				if (ladder[i][j] == 1) {
					x--;
					continue;
				}//한줄에같은가로선방지

				if (ladder[i][j - 1] == 1) { //양옆에 같은 가로선 방지
					if (j != 0) {
						x--;
						continue;
					}
				}
				if (ladder[i][j + 1] == 1)
					if (j != 3) {
						x--;
						continue;
					}

				ladder[i][j] = 1;
			}
	}//<각 줄에 최소 3개의 가로줄>

	printf("1          2          3          4          5\n");
	for (i = 0;i<20;i++) {
		for (j = 0;j < 4;j++) {
			printf("|");

			if (ladder[i][j] == 0)
				printf("          ");
			else if (ladder[i][j] == 1)
				printf("----------");
		}
		printf("|\n");
	}//<사디리 출력>
	printf("A          B          C          D          E\n");

	int result;
	for (x = 1;x <= 5;x++) { //x변수 = 사람번호
		i = 0;  //i(가로줄) 초기화
		j = x - 1;

		while (i != 20) {
			if (j == 0) {
				if (ladder[i][j] == 0)
					i++;
				if (ladder[i][j] == 1)
				    i++, j++;
			}
			else if (j == 4) {

				if (ladder[i][j-1] == 0)
					i++;
				if (ladder[i][j-1] == 1)
				    i++,j--;
			}
			else {
				if (ladder[i][j] == 0 && ladder[i][j - 1] == 0)
					i++;
				if (ladder[i][j] == 1)
					j++, i++;
				if (ladder[i][j] == 0 && ladder[i][j - 1] == 1)
					j--, i++;
			}
		}
		printf("%d -> %c\n", x , 'A' + j);
	}//<사다리 결과 출력>
	printf("20170299 김유빈\n");
}