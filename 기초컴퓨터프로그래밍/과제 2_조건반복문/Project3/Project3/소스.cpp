#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int year, month, day, totalday, i; //변수 totalday가 1900년 1월 1일부터 입력날짜까지 며칠이 지났는지를 계산

	printf("yyyy mm dd ? ");
	scanf("%d %d %d", &year, &month, &day); 

	totalday = day - 1;    //먼저 날짜를 totalday에 넣어주는데 1900년1월1일부터 세므로 여기에 1을 빼기

	for (i = 1900; i < year; i++) {     //윤년을 계산하여 윤년일 때 366일, 윤년이 아닐 때 365일을 더한다
		                                //단, 입력한 해의 바로 전까지만 계산
		if (i % 4 != 0 || ((i % 100 == 0) && (i % 400 != 0)))
			totalday += 365;
		else
			totalday += 366;
	}

	switch (month - 1) {        //입력한 월을 계산
	case 11: totalday += 30;
	case 10: totalday += 31;
	case  9: totalday += 30;
	case  8: totalday += 31;
	case  7: totalday += 31;
	case  6: totalday += 30;
	case  5: totalday += 31;
	case  4: totalday += 30;
	case  3: totalday += 31;
	case  2: totalday += 28;
	case  1: totalday += 31;
	}

	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
		totalday++;  //입력한 해가 윤년이면 2월은 29일이므로 totalday에 1을 더한다

	switch (totalday % 7) {            //마지막은 전체 일수를 더한 totalday를 통해 입력한 날짜의 요일을 계산
	case 0: printf("월요일입니다.\n");
		break;
	case 1: printf("화요일입니다.\n");
		break;
	case 2: printf("수요일입니다.\n");
		break;
	case 3: printf("목요일입니다.\n");
		break;
	case 4: printf("금요일입니다.\n");
		break;
	case 5: printf("토요일입니다.\n");
		break;
	case 6: printf("일요일입니다.\n");
		break;
	}

	printf("\n20170299 김유빈, 20165389 정다희\n");
}
