#include <stdio.h>
#include <math.h>
#define PI 3.1415726
#define RAD PI/180

int main()
{
	char buf[37][41] = { 0 };  //�迭 ��ĭ
	int i,j;   //i�� �迭�� ��, j�� �迭�� ĭ 
	int x, y;  //sin, cos ��
	           //index�� int�ڷ����� �ǹǷ� x,y �ڷ����� int��(double�� sin,cos�� ���� int�� �� ��ȯ - ����,�뷫���� �� ����) 
	printf("--------------------x--------------------\n");
	for (i = 0;i < 37;i++) {
		x = sin(i * 10 * RAD) * 20 + 20;
		y = cos(i * 10 * RAD) * 20 + 20;
		buf[i][20] = '|';              //'|'�� '*','+'���� ���� ����ϸ� sin,cos�� x���� ������ �� x�� ���
		buf[i][x] = '*';               //sin ���
		buf[i][y] = '+';               //cos ���
	}

	for (i = 0;i < 37;i++) {
		for (j = 0;j < 41;j++) 
			printf("%c", buf[i][j]);

		printf("\n");                  //1���� �� ����ϸ� �鿩���� 
		}
	printf("20170299 ������ \n\n");
}