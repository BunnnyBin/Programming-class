#include <stdio.h>

int main() {
	int i, total = 0, sub;

	for (i = 1;i < 100;i++) {
		total += i;
		printf("total = %d\n", total);
		if (total > 50)
			continue;
		sub = total * i;
		printf("sub = %d * %d\n", total, i);
	}
}