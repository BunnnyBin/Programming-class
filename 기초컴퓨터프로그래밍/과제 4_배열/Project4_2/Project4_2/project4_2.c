#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int buf[10][10] = { 0 };
	int n;

	printf("3 ~ 9사이의 n의 값을 입력하시오: ");
	scanf("%d", &n);
	while (n % 2 == 0 || n < 3 || n>9) {               //만약 3~9 외의 값을 입력하면 다시 입력
		printf("3 ~ 9사이의 n의 값을 입력하시오: ");
		scanf("%d", &n);
	}

	int i = 0, j = n / 2 , x; //i는 줄, j는 칸

	for (x = 1;x <= n*n;x++) {
		buf[i][j] = x;    //숫자 입력
			
		i--, j++;         //다음 줄,칸으로 이동      

 		if (i < 0)        //이동칸이 화면버프를 벗어나는 경우 방지     
			i = n - 1;
		if (j > n - 1)
			j = 0;

		while (buf[i][j] != 0 && x!=n*n) {  //이동칸에 숫자가 이미 있을 때(단, 모든칸이 채워진 것 제외) 
			                                //숫자가 안 겹칠때까지 이동
			i++, j--;        //전칸으로 돌아가서
			if (i > n - 1)
				i = 0;
			if (j < 0)
				j = n - 1;
			i++;            //전칸 밑으로 이동        
			if (i > n - 1)  //밑으로 이동할때, 화면버프 벗어나는 거 방지
				i = 0;
		}
	}//변수x에대한 for문 끝

	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			printf("%-4d", buf[i][j]);    //한 줄(가로줄)씩 숫자 출력
			buf[i][n] += buf[i][j];       //가로줄의 총합 계산
		}
		printf("%-4d", buf[i][n]);        //가로줄의 총합 출력
		printf("\n");
	}

	for (j = 0;j < n;j++) {             
		for (i = 0;i < n;i++)             //마지막 줄에
			buf[n][j] += buf[i][j];       //세로줄 총합 계산
		printf("%-4d", buf[n][j]);        //세로줄 총합 출력
	}

	printf("\n\n20170299 김유빈\n");
}