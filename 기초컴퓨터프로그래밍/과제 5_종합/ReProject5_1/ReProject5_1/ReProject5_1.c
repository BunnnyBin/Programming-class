#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Generate_Lotto(int number[6]);

int main()
{
	int nth;
	int lotto[6];
	int array[1000][6] = { 0 };
	int i, j;
	int same = 0;

	srand((unsigned)time(NULL));

	printf("몇 개의 로또 번호를 생성할까요? ");
	scanf("%d", &nth);

	for (i = 0;i < nth;i++) {
		Generate_Lotto(lotto);

		for (j = 0;j < i;j++) {
			same = 0;  
			for (int x = 0; x < 6;x++)       
				for (int y = 0;y < 6;y++)
					if (array[j][x] == lotto[y])
						same++;

			if (same == 6) {                  
				Generate_Lotto(lotto);   
				j = 0;                    
			}
		}//j의 for문(lotto 숫자배열 중복 검사)

		for (j = 0;j < 6;j++)        
			array[i][j] = lotto[j];  

		printf("%3dth Lotto: ", i + 1);

		for (j = 0;j < 6;j++)        
			printf("%d ", lotto[j]);
		printf("\n");

	} //i의 for문
	printf("\n20170299_김유빈\n");
} //main

void Generate_Lotto(int number[6])
{
	static int  nth = 0;  //몇 번째 로또 번호를 만드는 것인지 저장 (main함수의 nth과 전혀 다른 변수)
	                      //지역정적변수 -> Generate_Lotto함수에 다시 돌아와도 카운팅되도록
	int i, j;

		nth++;            //로또 번호를 만드는게 몇 번째인지 카운트

	if (nth == 2) {
		number[0] = 1;
		number[1] = 3;
		number[2] = 13;
		number[3] = 31;
		number[4] = 41;
		number[5] = 45;
		
		return;
	}//2번째 로또와
	else if (nth == 4) {
		number[0] = 13;
		number[1] = 31;
		number[2] = 45;
		number[3] = 41;
		number[4] = 3;
		number[5] = 1;

		return;
	}//4번째 로또 배열을 같게 함 
	else {
		for (i = 0;i < 6;i++) 
			number[i] = rand() % 45 + 1;
	}//그 외 로또

	for (i = 0;i < 6;i++)            //로또숫자 중복 방지
			for (j = 0;j < 6;j++) {
				while (number[i] == number[j] && j != i)
					number[i] = rand() % 45 + 1;
			}
	
} //Generate_Lotto