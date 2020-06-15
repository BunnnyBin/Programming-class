#include <stdio.h>
#define STAR 42

int main()
{
	char buf[15][11] = { 0 };
	int i, j;

	buf[3][0] = STAR;
	buf[3][10] = STAR;
	buf[6][1] = STAR;
	buf[6][9] = STAR;
	buf[8][2] = STAR;
	buf[8][7] = STAR;
	buf[9][3] = STAR;
	buf[9][6] = STAR;
	buf[10][5] = STAR;

	for(i=0;i<15;i++) {
		for (j = 0;j < 11;j++) 
			printf("%c", buf[i][j]);
		
	    printf("\n");
		}
}