#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

struct RENT {
	int loan_date[3];
	int due_date[3];
    char loan_ISBN[20];
};

struct MEMBER {
	int num;        //ȸ����ȣ
	char name[20];
	int birth;
	char phone[15];
	struct RENT memrent[5];
};

struct BOOK {
	char title[40];
	char writer[30];
	char ISBN[20];
	int loan;       //�뿩 ����
};

void enter_loan(struct MEMBER mem[100], struct BOOK bok[100]) {
	char etname[20];
	char etISBN[20];
	int i;
	int x , y;
	struct tm *date;
	time_t t;

	while (1) {
	   i = 0;
	   printf("ȸ�� �̸�: ");
	   gets(etname);

	   while (mem[i].num != 0) {
		   if (!strcmp(mem[i].name, etname))
			   break;
		   i++;
	   }
	   if (!strcmp(mem[i].name, etname))
		   break;
	   else printf("�ٽ� �Է��ϼ���!\n");  //�̸� �߸��Է� ����
	}//ȸ�� ��ܿ��� �ش� ȸ�� ã��

	printf("å�� ISBN: ");
	gets(etISBN);
	for (x = 0;x < 4;x++) {
		if (!strcmp(etISBN, bok[x].ISBN)) {
			if (bok[x].loan == 1) {
				printf("�̹� �뿩�� �����Դϴ�. \n");
				return;
			}

			else if (bok[x].loan == 0) {
				for (y = 0;y < 4;y++)
					if (mem[i].memrent[y].loan_date[0] == 0) {
						t = time(NULL);
						date = localtime(&t);
						mem[i].memrent[y].loan_date[0] = date->tm_year + 1900;
						mem[i].memrent[y].loan_date[1] = date->tm_mon + 1;
						mem[i].memrent[y].loan_date[2] = date->tm_mday;

						t += (24 * 60 * 60) * 7;
						date = localtime(&t);
						mem[i].memrent[y].due_date[0] = date->tm_year + 1900;
						mem[i].memrent[y].due_date[1] = date->tm_mon + 1;
						mem[i].memrent[y].due_date[2] = date->tm_mday;

						strcpy(mem[i].memrent[y].loan_ISBN, etISBN);

						bok[x].loan = 1;

						break;  //y�ݺ���
					}
			}//else if
			break; //x�ݺ���
		}//if - �ش� å �߰�
	}//x�ݺ���
	
}

void enter_due(struct MEMBER mem[100], struct BOOK bok[100]) {
	char etISBN[20];
	char etname[20];
	int i = 0;
	int x, y;

	while (1) {
		i = 0;
		printf("ȸ�� �̸�: ");
		gets(etname);

		while (mem[i].num != 0) {
			if (!strcmp(mem[i].name, etname))
				break;
			i++;
		}
		if (!strcmp(mem[i].name, etname))
			break;
		else printf("�ٽ� �Է��ϼ���!\n");  
	}

	printf("�ݳ� ������ ISBN: ");
	gets(etISBN);
	for (x = 0;x < 4;x++) {
		if (!strcmp(etISBN, mem[i].memrent[x].loan_ISBN)) {
			for (y = 0;y < 3;y++) {
				mem[i].memrent[x].loan_date[y] = 0;
				mem[i].memrent[x].due_date[y] = 0;
			}//0���� �ʱ�ȭ(����)
			strcpy(mem[i].memrent[x].loan_ISBN,"");
		}

		if (!strcmp(etISBN, bok[x].ISBN))
			bok[x].loan = 0; //�ش� ���� �ݳ� �Ϸ�
	}
}

void look_loanbook(struct MEMBER mem[100],struct BOOK bok[100]) {
	char etname[20];
	int i = 0;

	while (1) {
		i = 0;
		printf("ȸ�� �̸�: ");
		gets(etname);

		while (mem[i].num != 0) {
			if (!strcmp(mem[i].name, etname))
				break;
			i++;
		}
		if (!strcmp(mem[i].name, etname))
			break;
		else printf("�ٽ� �Է��ϼ���!\n");  
	}

	int x = 0,y;
	for(x = 0;x < 4; x++) {
		for (y = 0;y < 4;y++)
			if (!strcmp(mem[i].memrent[x].loan_ISBN, bok[y].ISBN)) {
				printf("<TITLE>                       <WRITER>                  <ISBN>\n");
				printf("%-30s%-25s %s\n", bok[y].title, bok[y].writer, bok[y].ISBN);
				printf("<LOAN_DATE>      <DUE_DATE>\n");
				printf("%d��%d��%d��   %d��%d��%d��\n", mem[i].memrent[x].loan_date[0], mem[i].memrent[x].loan_date[1], mem[i].memrent[x].loan_date[2], mem[i].memrent[x].due_date[0], mem[i].memrent[x].due_date[1], mem[i].memrent[x].due_date[2]);
				printf("-------------------------------------------------------------------------------\n");
			}
	}
}

void look_member(struct MEMBER mem[100]) {
	int i ,j;

	    printf("<No.> <NAME>          <BIRTH_DATE>  <PHONE_NUMBER>\n");
	for(j = 1;j < 100;j++) {
		for (i = 0;i < 100;i++) 
			if (mem[i].num == j) {
				printf("%d     %-15s %-13d %s\n", mem[i].num, mem[i].name, mem[i].birth, mem[i].phone);
				break;
			}
		if (i == 100)
			break;
	}//ȸ����ȣ�� ���� �迭
}

void look_book(struct BOOK bok[100]) {
	int i = 0;
	printf("<TITLE>                         <WRITER>                    <ISBN>\n");
	for (i = 0;i < 4;i++) 
		printf("%-32s%-28s %s\n", bok[i].title,bok[i].writer,bok[i].ISBN);
}

int main() {
	struct MEMBER member[100] = { {1,"KIM YOUBIN",19960918,"010-5040-7540"},
	                              {5,"HO YOUSIN",20010630,"010-8670-6210"},
	                              {2,"LEE SOONHEE",19680416,"010-6210-7540"},
	                              {3, "KIM MAN",19661020,"010-5505-7540"},
	                              {4,"PARK SAE",19960516,"010-6842-7952"}
	};

	struct BOOK book[100] = { {"Howl's Moving Castle","Diana Wynne Jones","979-11-86560-36-5"},
	                          {"Harry Potter","Joan K. Rowling","856-26-46565-38-7"},
	                          {"The Little Mermaid","Hans Christian Andersen","759-15-15653-85-4"},
	                          {"Walk Two Moons","Sharon Creech","123-43-47368-55-1"} 
	};//å �� 4������ ����

	char user[10];

	while (1) {
		printf("ȸ�� ��ȸ, ���� ��� ��ȸ, å �뿩 �Է�, å �ݳ� �Է�, ���� �뿩 ��� ��ȸ �� ��� ����� ���Ͻʴϱ�?\n-> ");
		gets(user);

		if (!strcmp(user,"ȸ�� ��ȸ"))
			look_member(member);
		else if (!strcmp(user, "���� ��� ��ȸ"))
			look_book(book);
		else if (!strcmp(user, "å �뿩 �Է�"))
			enter_loan(member,book);
		else if (!strcmp(user, "å �ݳ� �Է�"))
			enter_due(member,book);
		else if (!strcmp(user, "���� �뿩 ��� ��ȸ"))
			look_loanbook(member, book);
		else 
			printf("�ٽ� �Է����ּ���.\n");
		printf("-------------------------------------------------------------------------------\n");
	}
	
}