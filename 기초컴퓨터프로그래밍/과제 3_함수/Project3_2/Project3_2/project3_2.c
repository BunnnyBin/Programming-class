#include <stdio.h>
#include <math.h>
#define PI 3.1415726
#define RAD PI/180

int main()
{
	int angle, x; //angle�� ����, x�� ĭ ��

	printf("--------------------x--------------------\n\n");

	for (angle = 0; angle <= 360;angle += 10) {

		if (angle == 0) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("+\n");
		}  //<������ 0�� ��>


		else if( angle <= 45) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)  //sin�Լ� �׸��� �� ��ĭ
				if (x == 0)          //��ĭ ä�� �� x���� ������ x�� �׸���
					printf("|");
				else printf(" ");

				printf("*");  //sin�Լ� ǥ��

				for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)  //sin(*)���� cos(+) ������ ��ĭ
					printf(" ");
				printf("+\n"); //���������� cos(+) ǥ��

		} //<������ 0���� sin�� cos�� ������ 45�� ���� �϶�>

		else if( angle<90) {

			for (x = -20; x < cos(RAD*angle) * 20; x++)  //cos(+)ǥ�� ������ ��ĭ
				if (x == 0)
					printf("|");  //��ĭ �߰��� x��
				else printf(" ");

				printf("+"); //cos�Լ� ǥ��

				for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++) //cos(+)���� sin(*)������ ��ĭ
					printf(" ");

				printf("*\n"); //���������� sin�Լ� ǥ��

		} // <������ 45������ cos�� ���� 0�� �Ǵ� 90������>

		else if (angle == 90) {
			for (x = 1; x <= 20;x++)
				printf(" ");
			printf("+");

			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*\n");
		} // <������ 90�� �϶�>

		else if (angle < 180) {    //45~90���� ����

			for (x = -20; x < cos(RAD*angle) * 20; x++)
				printf(" ");

			printf("+");

			for (x = cos(RAD*angle) * 20 + 1;x <= sin(RAD*angle) * 20;x++)
				if (x == 0)
					printf("|");
				else printf(" ");

				printf("*\n");
		} //<������ 90������ sin�� 0�� �Ǵ� 180������>

		else if (angle == 180) {
			printf("+");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("*\n");
		} //<������ 180���� ��>

		else if( angle <= 225) {

			for (x = -20;x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < 0;x++)    //sin,cos �Ѵ� x�� �׸��� ���� �׷����Ƿ�
				printf(" ");                                //��ĭ �߰��� x���� �׸��� ����
			printf("|\n");                                  //���� sin(*)�׸��� ���� �ٽ� ��ĭ ���� x�� �׷�����

		} //<������ 180������ sin�� cos�� ������ 225������>

		else if( angle < 270) {    //�������� sin�Լ� ������ cos�Լ� ǥ��
			for (x = -20;x < sin(RAD*angle) * 20;x++)
				printf(" ");
			printf("*");

			for (x = sin(RAD*angle) * 20 + 1; x < cos(RAD*angle) * 20;x++)
				printf(" ");
			printf("+");

			for (x = cos(RAD*angle) * 20 + 1; x < 0; x++)  //���⼭�� x���� ���� ������ ��ĭ�� ������
				printf(" ");
			printf("|\n");
		} // <������ 225������ cos�� 0�� 270������>

		else if (angle == 270) {
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			printf("+\n");
		}// <������ 270�� �� ��>

		else if( angle < 360) {

			for (x = -20; x < sin(RAD*angle) * 20; x++)
				printf(" ");

			printf("*");

			for (x = sin(RAD*angle) * 20 + 1;x <= cos(RAD*angle) * 20;x++)
				if (x == 0)        //���⼭�� sin�� cos ��ĭ �߰��� x���� ǥ��
					printf("|");
				else printf(" ");

				printf("+\n");

		}// <������ 270������ 360������>

		else if (angle == 360) {
			for (x = 1;x <= 20;x++)
				printf(" ");
			printf("*");

			for (x = 1;x < 20;x++)
				printf(" ");
			
		} //<������ 360�� �϶�>

	}

	printf("+\n\n\n");
	printf("20170299 ������\n\n");
}