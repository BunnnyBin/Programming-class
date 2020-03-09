#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 구조체 
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
	
	// 학생수 입력 받기  
	printf("학생수 입력 : ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		// 동적 할당 
		data[i] = (STUDENT *)malloc(sizeof(STUDENT));
		
		// 학번과 성적 입력 받기 
		printf("%d번째 학생 학번 입력 : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->stdid=buffer;
		printf("%d번째 학생 국어 입력 : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->kor=buffer;
		printf("%d번째 학생 영어 입력 : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->eng=buffer;
		printf("%d번째 학생 수학 입력 : ",i+1 ); 
		scanf("%d",&buffer);
		data[i]->math=buffer;
	}
	
	// 성적 출력 
	for(i=0;i<num;i++)
	{
		printf("학번:%d ",data[i]->stdid);
		printf("국어:%d ",data[i]->kor);
		printf("영어:%d ",data[i]->eng);
		printf("수학:%d ",data[i]->math);
		printf("\n"); 
	}
}
