#include <stdio.h>
#include <math.h>
#define PI 3.1415726
#define RAD PI/180

int main()
{
	char buf[37][41] = { 0 };  //배열 빈칸
	int i,j;   //i는 배열의 줄, j는 배열의 칸 
	int x, y;  //sin, cos 값
	           //index는 int자료형만 되므로 x,y 자료형도 int형(double형 sin,cos의 값이 int로 형 변환 - 버림,대략적인 값 추출) 
	printf("--------------------x--------------------\n");
	for (i = 0;i < 37;i++) {
		x = sin(i * 10 * RAD) * 20 + 20;
		y = cos(i * 10 * RAD) * 20 + 20;
		buf[i][20] = '|';              //'|'를 '*','+'보다 먼저 출력하면 sin,cos과 x축이 겹쳤을 때 x축 출력
		buf[i][x] = '*';               //sin 출력
		buf[i][y] = '+';               //cos 출력
	}

	for (i = 0;i < 37;i++) {
		for (j = 0;j < 41;j++) 
			printf("%c", buf[i][j]);

		printf("\n");                  //1줄을 다 출력하면 들여쓰기 
		}
	printf("20170299 김유빈 \n\n");
}