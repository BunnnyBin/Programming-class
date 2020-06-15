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
			same = 0;  //변수 same을 0으로 초기화

			for(int x = 0; x < 6;x++)       //array배열 j줄에 lotto와 같은 숫자배열이 있는지 확인
			   for (int y = 0;y < 6;y++)
				  if (array[j][x] == lotto[y])
					  same++;

			if (same == 6) {              //lotto와 같은 숫자배열이 이미 있다면    
				Generate_Lotto(lotto);    //다시 lotto 뽑기
				j = 0;                    //새로 뽑은 lotto도 전에 같은 숫자배열이 있었는지 확인( array 0번째줄부터 다시 확인) 
			}
		}//j의 for문(lotto 숫자배열 중복 검사)

		for (j = 0;j < 6;j++)        //lotto가 전의 배열들과 중복이 안된다면
			array[i][j] = lotto[j];  //array에 새로 저장
           
		printf("%3dth Lotto: ", i + 1);

		for (j = 0;j < 6;j++)        //lotto 출력  
			printf("%d ", lotto[j]);
		printf("\n");

	} //i의 for문
	printf("\n20170299_김유빈\n");
} //main

void Generate_Lotto(int number[6])
{
	int i, j;
	
	for (i = 0;i < 6;i++)
		number[i] = rand() % 45 + 1;    //로또 랜덤하게 숫자 생성

	for (i = 0;i<6;i++)
		for (j = 0;j < 6;j++) {
			while (number[i] == number[j] && j != i)   //내부에 중복되는 숫자 방지
				number[i] = rand() % 45 + 1;
		} 
} //Generate_Lotto