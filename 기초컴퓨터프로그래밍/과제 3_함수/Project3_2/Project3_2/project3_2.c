#include <stdio.h>
#include <math.h>
#define PI 3.1415726
#define RAD PI/180

int main()
{
	int angle, x; //angle은 각도, x는 칸 수

	printf("--------------------x--------------------\n\n");

	for (angle = 0; angle <= 360;angle += 10) {

		if (angle == 0) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("+\n");
		}  //<각도가 0일 때>


		else if( angle <= 45) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)  //sin함수 그리기 전 빈칸
				if (x == 0)          //빈칸 채울 때 x축을 만나면 x축 그리기
					printf("|");
				else printf(" ");

				printf("*");  //sin함수 표시

				for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)  //sin(*)에서 cos(+) 사이의 빈칸
					printf(" ");
				printf("+\n"); //마지막으로 cos(+) 표시

		} //<각도가 0에서 sin과 cos이 만나는 45도 사이 일때>

		else if( angle<90) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)  //cos(+)표시 이전에 빈칸
				if (x == 0)
					printf("|");  //빈칸 중간에 x축
				else printf(" ");

				printf("+"); //cos함수 표시

				for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++) //cos(+)에서 sin(*)사이의 빈칸
					printf(" ");

				printf("*\n"); //마지막으로 sin함수 표시

		} // <각도가 45도에서 cos의 값이 0이 되는 90도까지>

		else if (angle == 90) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("+");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*\n");
		} // <각도가 90도 일때>

		else if (angle < 180) {    //45~90도와 동일

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				printf(" ");

			printf("+");

			for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
				if (x == 0)
					printf("|");
				else printf(" ");

				printf("*\n");
		} //<각도가 90도에서 sin이 0이 되는 180도까지>

		else if (angle == 180) {
			printf("+");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("*\n");
		} //<각도가 180도일 때>

		else if( angle <= 225) {

			for (x = -20;x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < 0;x++)    //sin,cos 둘다 x축 그리기 전에 그려지므로
				printf(" ");                                //빈칸 중간에 x축을 그리지 못함
			printf("|\n");                                  //따라서 sin(*)그리고 나서 다시 빈칸 세고 x축 그려야함

		} //<각도가 180도에서 sin과 cos이 만나는 225도까지>

		else if( angle < 270) {    //이제부터 sin함수 다음에 cos함수 표시
			for (x = -20;x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < 0; x++)  //여기서도 x축을 위한 별도의 빈칸을 세야함
				printf(" ");
			printf("|\n");
		} // <각도가 225도에서 cos이 0인 270도까지>

		else if (angle == 270) {
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n");
		}// <각도가 270도 일 때>

		else if( angle < 360) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
				printf(" ");

			printf("*");

			for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
				if (x == 0)        //여기서는 sin과 cos 빈칸 중간에 x축을 표시
					printf("|");
				else printf(" ");

				printf("+\n");

		}// <각도가 270도부터 360도까지>

		else if (angle == 360) {
			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			
		} //<각도가 360도 일때>

	}

	printf("+\n\n\n");
	printf("20170299 김유빈\n\n");
}