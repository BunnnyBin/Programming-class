#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str1[45];
char str2[45];
char restr1[45];
char restr2[45];

int plus() {
	char result[100] = "";
	char long_s[45] = "";
	char short_s[45] = "";

	int num, carry = 0;
	int x;

	if (strlen(restr1) >= strlen(restr2)) {
		strcpy(long_s, restr1);
		strcpy(short_s, restr2);
	}
	else {
		strcpy(short_s, restr1);
		strcpy(long_s, restr2);
	}//큰 숫자, 작은 숫자 구분

	int def = strlen(long_s) - strlen(short_s);
	for (x = 0;x < def;x++) 
		strcat(short_s, "0");   //작은 숫자에 0을 채우기
	
	for (x = 0;x < strlen(long_s);x++) {
		num = (long_s[x] - '0') + (short_s[x] - '0') + carry;

		if (num > 9) {
			carry = 1;  //올림
			num -= 10;
		}
		else carry = 0;

		result[x] = num + '0';
	}
	if (carry == 1) {
		result[x] = '1';
	} //마지막 올림

	printf("= ");
	if (str1[0] == '-')
		printf("-");  //음수(-) 표시
	for (x = strlen(result);x > 0;x--) 
		printf("%c", result[x - 1]);    //결과 거꾸로 출력
}

int minus() {
	char result[100] = "";
	char long_s[45] = "";
	char short_s[45] = "";

	int num, carry = 0;
	int x;
	int m;   //음수 표시

	if (strlen(restr1) > strlen(restr2)) {
		strcpy(long_s, restr1);
		strcpy(short_s, restr2);
		if (str1[0] == '-')
			m = 1;
		else m = 0;
	}

	else if (strlen(restr1) == strlen(restr2)) {
		for (x = strlen(restr1) - 1;x >=0 ;x--) {
			if (restr1[x] > restr2[x]) {
				strcpy(long_s, restr1);
				strcpy(short_s, restr2);
				if (str1[0] == '-')
					m = 1;
				else m = 0;

				break;
			}
			else if (restr1[x] < restr2[x]) {
				strcpy(short_s, restr1);
				strcpy(long_s, restr2);

				if (str1[0] == '-')
					m = 0;
				else m = 1;

				break;
			}

		}
	}

	else {
		strcpy(short_s, restr1);
		strcpy(long_s, restr2);
		if (str1[0] == '-')
			m = 0;
		else m = 1;
	}// 어느 값이 더 큰지 비교

	int def = strlen(long_s) - strlen(short_s);
	for (x = 0;x < def;x++)
		strcat(short_s, "0");

	for (x = 0;x < strlen(long_s);x++) {
		num = (long_s[x] - '0') - carry - (short_s[x] - '0');

		if (num < 0) {
			carry = 1;
			num += 10;
		}
		else carry = 0;

		result[x] = num + '0';
	}

	printf("= ");
	if (m == 1)
		printf("-");
	for (x = strlen(result);x > 0;x--) 
		printf("%c", result[x - 1]);//출력
}

int mult() {
	char result[100] = "";
	char mult_plus[50][100] = { "" ,"" };
	int num, carry;
	int x, y;
	
	for (x = 0;x < 49;x++)
		for (y = 0;y < 99;y++)
			mult_plus[x][y] = '0';

	for (x = 0;x < strlen(restr2);x++) { //mult_plus: x 세로, y 가로
		carry = 0;

		for (y = 0;y < strlen(restr1);y++) {
			num = (restr1[y] - '0') * (restr2[x] - '0') + carry;

			if (num > 9) {
				carry = num / 10;
				num = num % 10;
			}
			else carry = 0;

			mult_plus[x][x + y] = num + '0';
		}
		mult_plus[x][x + y] = carry + '0'; //마지막 올림
	}//곱하기

	carry = 0;
	int last = x + y;  //최종 결과값 길이
	for (x = 0;x < last;x++) {  //x: 가로, y: 세로
		num = carry;
		for (y = 0;y < strlen(restr2);y++) 
			num += (mult_plus[y][x] - '0');
		
		if (num > 9) {
			carry = num / 10;
			num = num % 10;
		}
		else carry = 0;

		result[x] = num + '0';
	}//더하기
	if(carry != 0)
	  result[x] = carry + '0';//마지막 올림
	
	printf("= ");
	if ((str1[0] != '-' && str2[0] == '-') || (str1[0] == '-' && str2[0] != '-'))
		printf("-"); //음수 출력

	for (x = strlen(result);x > 0;x--) 
		printf("%c", result[x - 1]);//출력
}

int main() {
	char str3[10];  //명령어;
	int x;

	while (1) {
		printf("\ninput X. ");
		gets(str1);
		printf("input Y. ");
		gets(str2);

		printf("덧셈: X + Y,뺄셈: X - Y, 곱셈: X * Y를 입력해주세요. \n");
		gets(str3);
		while (1) {
			if (!strcmp(str3, "X + Y") || !strcmp(str3, "X - Y") || !strcmp(str3, "X * Y"))
				break;
			printf("다시 입력해주세요!\n");
			gets(str3);
		}//잘못 입력 방지

		for (x = 0;x < 44;x++) {
			restr1[x] = 0;
			restr2[x] = 0;
		}; //초기화!!!!!!!!!!!!!!!!!!!!!!
		for (x = 0;x < strlen(str1);x++) {
			if (str1[strlen(str1) - 1 - x] == '-')
				continue; //(-) 저장안하기
			restr1[x] = str1[strlen(str1) - 1 - x];
		}
		for (x = 0;x < strlen(str2);x++) {
			if (str2[strlen(str2) - 1 - x] == '-')
				continue;
			restr2[x] = str2[strlen(str2) - 1 - x];
		}//REVERSE

		if (!strcmp(str3, "X + Y")) {
			if ((str1[0] != '-'&&str2[0] == '-') || (str1[0] == '-' && str2[0] != '-'))
				minus();
			else plus();
		}
		
		else if (!strcmp(str3, "X - Y")) {
			if ((str1[0] != '-'&&str2[0] == '-') || (str1[0] == '-' && str2[0] != '-'))
				plus();
			else minus();
		}
		
		else if (!strcmp(str3, "X * Y"))
			mult();	
	}
}