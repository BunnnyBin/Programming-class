#include <stdio.h>

int main(void)
{
	int a[10];
	int i, j, k, freq[10] = { 0 };

	for (i = 0; i<10; i++)
	{
		printf("%d ��° ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &a[i]);
		printf("\n");
	} //���� �Է�

	for (i = 0; i<10; i = i + 1)
	{
		k = a[i] / 10;
		freq[k] = freq[k] + 1;   
	} //�������� ���ڸ������ ����

	for (i = 0; i<10; i++) //����, 0-9����
	{
		printf("%2d ~ %2d: ", i * 10, i * 10 + 9);  //����: 90-100�� �� ������ ����
		for (j = 0; j<freq[i]; j++)  //j�� ��ǥ��
			printf("*");

		printf("\n");
	}
	return 0;
}