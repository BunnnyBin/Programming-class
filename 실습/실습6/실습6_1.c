#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char  *str[100];
	char buffer[30];
	char end[10] = "end";
	
	int i,k=0; 
	
	while(1){
		gets(buffer);
		
		//end를 입력하면 멈추자  
		if(!strcmp(buffer,end)){
			break;
		}
		
		//메모리 할당  
		str[i]= (char*) malloc(sizeof(char) * 30);
		strcpy(str[i],buffer);
		
		i++;
	
	} 
	
	// 출력 
	for(k=0;k<i;k++)
	{
		printf("%d : %s \n",k,str[k]);
	}
	
	return 0;
}
