#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int year, month, day, totalday, i; //���� totalday�� 1900�� 1�� 1�Ϻ��� �Է³�¥���� ��ĥ�� ���������� ���

	printf("yyyy mm dd ? ");
	scanf("%d %d %d", &year, &month, &day); 

	totalday = day - 1;    //���� ��¥�� totalday�� �־��ִµ� 1900��1��1�Ϻ��� ���Ƿ� ���⿡ 1�� ����

	for (i = 1900; i < year; i++) {     //������ ����Ͽ� ������ �� 366��, ������ �ƴ� �� 365���� ���Ѵ�
		                                //��, �Է��� ���� �ٷ� �������� ���
		if (i % 4 != 0 || ((i % 100 == 0) && (i % 400 != 0)))
			totalday += 365;
		else
			totalday += 366;
	}

	switch (month - 1) {        //�Է��� ���� ���
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
		totalday++;  //�Է��� �ذ� �����̸� 2���� 29���̹Ƿ� totalday�� 1�� ���Ѵ�

	switch (totalday % 7) {            //�������� ��ü �ϼ��� ���� totalday�� ���� �Է��� ��¥�� ������ ���
	case 0: printf("�������Դϴ�.\n");
		break;
	case 1: printf("ȭ�����Դϴ�.\n");
		break;
	case 2: printf("�������Դϴ�.\n");
		break;
	case 3: printf("������Դϴ�.\n");
		break;
	case 4: printf("�ݿ����Դϴ�.\n");
		break;
	case 5: printf("������Դϴ�.\n");
		break;
	case 6: printf("�Ͽ����Դϴ�.\n");
		break;
	}

	printf("\n20170299 ������, 20165389 ������\n");
}
