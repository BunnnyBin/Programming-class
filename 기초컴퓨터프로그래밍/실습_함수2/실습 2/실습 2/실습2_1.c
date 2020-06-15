#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main()
{
	clock_t start, end;

	start = clock();
	
		while (1) {
			end = clock();

			if ((end - start) == 1000) {
				printf("*");
				start = end;

			}

	}

}