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
		}  //������ 0�� ��


		if (angle>0 && angle <= 45) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
				if (x == 0)          //��ĭ ä�� �� x���� ������ x�� �׸���
					printf("|");
				else printf(" ");   

			printf("*");

			for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+\n");

		} //������ 0���� sin�� cos�� ������ 45�� ���� �϶�

		if (angle >= 45 && angle<90) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				if (x == 0)
					printf("|");
				else printf(" ");

				printf("+");

				for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
					printf(" ");

				printf("*\n");

		} // ������ 45������ cos�� ���� 0�� �Ǵ� 90������
		
		if (angle == 90) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("+");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*\n");
		} // ������ 90�� �϶�

		if (angle > 90 && angle < 180) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				printf(" ");

			printf("+");

			for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
				if (x == 0)
					printf("|");
				else printf(" ");

			printf("*\n");
		} //������ 90������ sin�� 0�� �Ǵ� 180������

		if (angle == 180) {
			printf("+");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("*\n");
		} //������ 180���� ��

		if (angle > 180 && angle <= 225) {

			for (x = -20;x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < 0;x++)    //180������270���� �� x�� �׸��°Ϳ� ����
				printf(" ");
			printf("|\n");

		} //������ 180������ sin�� cos�� ������ 225������

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
		} // ������ 225������ cos�� 0�� 270������

		if (angle == 270) {
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n");
		}// ������ 270�� �� ��

		if (angle > 270 && angle < 360) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
			       printf(" ");

				printf("*");

				for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
					if (x == 0)
						printf("|");
					else printf(" ");

				printf("+\n");

		}// ������ 270������ 360������

		if (angle == 360) {
			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n\n\n");
		} //������ 360�� �϶�

	}

	printf("20170299 ������\n\n");
}