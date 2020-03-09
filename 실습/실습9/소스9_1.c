#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct STUDENT {
	int num;
	int kor;
	int eng;
	int mat;
};

int main() {
	struct STUDENT student[4];
	FILE * pFile;
	char str[20];
	char str2[20];
	int i;
	char * token;
	char * nom;
	pFile = fopen("score.csv", "r");
	if (pFile == NULL)
		printf("파일 실패\n");

	i = 0;
	while (!feof(pFile)) {
		nom = fgets(str, 20, pFile);
		if (nom == NULL)
			break;

		strcpy(str2, str);
		token = strtok(str2, ",");
		student[i].num = atoi(token);
		token = strtok(NULL, ",");
		student[i].kor = atoi(token);
		token = strtok(NULL, ",");
		student[i].eng = atoi(token);
		token = strtok(NULL, ",");
		student[i].mat = atoi(token);

		i++;
	}
	fclose(pFile);

	for (i = 0; i < 4; i++) 
		printf("%d kor = %d, eng = %d, math = %d\n", student[i].num, student[i].kor, student[i].eng, student[i].mat);
	
}