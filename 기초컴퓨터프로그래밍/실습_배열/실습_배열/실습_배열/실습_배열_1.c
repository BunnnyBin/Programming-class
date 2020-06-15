#include <stdio.h>

int main()
{
	int x,j;

	printf("2 ");

	for (x=3; x<=1000; x++) 
		for (j = 2; j < x; j++) {
			if (x%j == 0) {
				x++;
				j = 1;
			}
			else if (j == x - 1)
				printf("%d ", x);
		}
	printf("\n");
}