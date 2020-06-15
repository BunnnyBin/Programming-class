#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int N, M, row, gap, i, temp = 0;

	printf("N : ");
	scanf("%d", &N);
	printf("M : ");
	scanf("%d", &M);

	while ((N == 3 || N == 4) && M % 2 == 0) {  //N=3,4일 때 M의 값이 홀수가 아닐 때 다시 입력받도록 하는 장치
		printf("N 값이 3이나 4일 경우에는 M 값은 홀수만 가능합니다. M 값을 다시 입력하세요.\n");
		printf("M : ");
		scanf("%d", &M);
	}



	switch (N)
	{
	case 1: for (row = 1; row <= M; row++) {   //'줄'에 따라 숫자의 개수와 빈칸을 조절

		for (gap = 0; gap < M - row; gap++)    //예를 들어 M=4일 때, 첫째 줄 빈칸이 3칸,둘째 줄 빈칸 2칸,셋째 줄 빈칸 1칸, 넷째 줄 빈칸 0칸이다. 
			printf(" ");                       //이때 빈칸 규칙을 발견하여 줄 마다 M-row까지 빈칸을 만듦 

		for (i = 1; i <= row; i++)             //첫째 줄에 숫자1, 둘째 줄에 숫자 2,3, 셋째 줄에 숫자 4,5,6, ... 를 출력
			printf("%3d", i + temp);           //이때 %3d를 한 이유는 M값이 커질수록 숫자가 겹치지 않게 하기 위해서

		temp += row;     //다음 줄로 넘어가도 다시 숫자1로 돌아가지 않고 그대로 1씩 더해지도록 하는 장치 (변수 temp)

		printf("\n");    //첫째 줄에 숫자1개, 둘째 줄에 숫자2개...씩으로 줄에 따른 숫자의 갯수를 조절함
		}
			break;


	case 2: for (row = M; row > 0; row--) {     //N=1일 때와 반대로 만들기 위해 row를 M부터 시작하여 1개씩 줄여서 센다
		                                        //나머지는 N=1일 때와 동일
		for (gap = 0; gap < M - row; gap++)   
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }
			break;
			

	case 3: for (row = 1; row <= M / 2 + 1; row++) {   //다이아몬드는 N=1과 N=2를 합침
		                                               //먼저 N=1일 때를 출력. 단, 여기서 규칙을 발견하여 M/2+1개 줄까지만 출력. 
		for (gap = 0; gap < M / 2 + 1 - row; gap++)
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }

			for (row = M / 2; row > 0; row--) {     //N=2일 때를 출력. 이때는 M/2개의 줄만 출력. M/2부터 1개의 줄을 출력

				for (gap = 0; gap <= M / 2 - row; gap++)
					printf(" ");

				for (i = 1; i <= row; i++)          
					printf("%3d", i + temp);        //temp변수의 값은 N=1일때의 값을 그대로 이어 받으므로 숫자는 계속 증가함
				 
				temp += row;

				printf("\n");
			}
			break;


	case 4: for (row = M / 2 + 1; row > 0; row--) {     //역삼각형은 N=2와 N=1을 합침
		                                                //N=3일때와 비슷하게 N=2를 먼저 출력하는데 M/2+1부터 1까지 줄을 센다
		for (gap = 0; gap <= M / 2 + 1 - row; gap++)
			printf(" ");

		for (i = 1; i <= row; i++)
			printf("%3d", i + temp);

		temp += row;

		printf("\n");
	    }

			for (row = 2; row <= M / 2 + 1; row++) {    //N=1을 출력. 주의 점은 모래시계에 가운데 숫자는 이미 N=2일때 출력해서
				                                        //row=2부터 시작
				for (gap = 0; gap < M / 2 + 1 - row; gap++)
					printf(" ");

				for (i = 1; i <= row; i++)
					printf("%3d", i + temp);

				temp += row;

				printf("\n");
			}
	
	}


	printf("\n20170299 김유빈, 20165389 정다희\n");
}