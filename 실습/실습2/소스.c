#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char str[50] = "";
	char result[1000] = "";

	int count = 0;  //�ܾ� ��

	for (;;) {

		gets(str);

		if (!strcmp(str, "!N"))
			printf("%d�ܾ��Դϴ�.\n", count);


		else if (!strcmp(str, "!S")) {
			int i = 0;
			int v[5] = { 0 }; //���� ��

			while (result[i] != 0) {
				if (result[i] == 'a')
					v[0]++, i++;
				else if (result[i] == 'e')
					v[1]++, i++;
				else if (result[i] == 'i')
					v[2]++, i++;
				else if (result[i] == 'o')
					v[3]++, i++;
				else if (result[i] == 'u')
					v[4]++, i++;
				else i++;
			}
			printf("a = %d, e = %d, i = %d, o = %d, u = %d\n",v[0],v[1],v[2],v[3],v[4]);
		}
    
		else {
			if (str != 0)
				strcat(str, " ");  //���� �Է��ϸ� ������ ���� �߰�

			strcat(result, str);
			count++;

			printf("%s\n", result);
		}
	}
}
