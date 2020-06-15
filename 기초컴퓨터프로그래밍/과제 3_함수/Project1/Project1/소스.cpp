#include <stdio.h>
#include <math.h>
#define PI 3.1415726
#define RAD PI/180

int main()
{
	int angle, x;

	printf("--------------------x--------------------\n\n");

	for (angle = 0; angle <= 360;angle += 10) {

		if (angle == 0) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("+\n");
		}  //각도가 0일 때


		if (angle>0 && angle <= 45) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
				if (x == 0)          //빈칸 채울 때 x축을 만나면 x축 그리기
					printf("|");
				else printf(" ");   

			printf("*");

			for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+\n");

		} //각도가 0에서 sin과 cos이 만나는 45도 사이 일때

		if (angle >= 45 && angle<90) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				if (x == 0)
					printf("|");
				else printf(" ");

				printf("+");

				for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
					printf(" ");

				printf("*\n");

		} // 각도가 45도에서 cos의 값이 0이 되는 90도까지
		
		if (angle == 90) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("+");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*\n");
		} // 각도가 90도 일때

		if (angle > 90 && angle < 180) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				printf(" ");

			printf("+");

			for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
				if (x == 0)
					printf("|");
				else printf(" ");

			printf("*\n");
		} //각도가 90도에서 sin이 0이 되는 180도까지

		if (angle == 180) {
			printf("+");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("*\n");
		} //각도가 180도일 때

		if (angle > 180 && angle <= 225) {

			for (x = -20;x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < 0;x++)    //180도에서270도일 때 x축 그리는것에 주의
				printf(" ");
			printf("|\n");

		} //각도가 180도에서 sin과 cos이 만나는 225도까지

		if (angle > 225 && angle < 270) {
			for (x = -20;x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20+1; x < 0; x++)
				printf(" ");
			printf("|\n");
		} // 각도가 225도에서 cos이 0인 270도까지

		if (angle == 270) {
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n");
		}// 각도가 270도 일 때

		if (angle > 270 && angle < 360) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
			       printf(" ");

				printf("*");

				for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
					if (x == 0)
						printf("|");
					else printf(" ");

				printf("+\n");

		}// 각도가 270도부터 360도까지

		if (angle == 360) {
			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n\n\n");
		} //각도가 360도 일때

	}

	printf("20170299 김유빈\n\n");
}