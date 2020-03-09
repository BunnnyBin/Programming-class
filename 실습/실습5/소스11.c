#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct MEMBER {
	char name[10];
	char phone[20];
};

int main() {
	struct MEMBER member[4] = { {"KIM","010-3333-4444"},{"LEE","010-4545-6767"},{"PARK","011-4840-0192"},{"HONG","010-9988-7766"} };
	char user[5];
	char * f;
	int i;
	printf("검색할 이름 또는 전화번호는? ");
	gets(user);

	for (i = 0; i < 4; i++) {
		f = strstr(member[i].name, user);
		if (f == 0) {
			f = strstr(member[i].phone, user);
			if (f != 0) {
				printf("%s : %s", member[i].name, member[i].phone);
				break;
			}
		}
		else if (f != 0) {
			printf("%s : %s", member[i].name, member[i].phone);
			break;
		}
	}


}