#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �л� ����ü 
typedef struct student
{
	int stdid;
	int kor;
	int eng;
	int math;
	
}STUDENT;

int main(void)
{
	int num;
	int i=0;
	int buffer;
	
	STUDENT *data[30];
	
	// �л��� �Է� �ޱ�  
	printf("�л��� �Է� : ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		// ���� �Ҵ� 
		data[i] = (STUDENT *)malloc(sizeof(STUDENT));
		
		// �й��� ���� �Է� �ޱ� 
		printf("%d��° �л� �й� �Է� : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->stdid=buffer;
		printf("%d��° �л� ���� �Է� : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->kor=buffer;
		printf("%d��° �л� ���� �Է� : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->eng=buffer;
		printf("%d��° �л� ���� �Է� : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->math=buffer;
	}
	
	// ���� ��� 
	for(i=0;i<num;i++)
	{
		printf("�й�:%d ",data[i]->stdid);
		printf("����:%d ",data[i]->kor);
		printf("����:%d ",data[i]->eng);
		printf("����:%d ",data[i]->math);
		printf("\n"); 
	}
}
