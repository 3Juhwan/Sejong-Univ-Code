#include<stdio.h>

int main() {
	int x = 1, y = 1, z = 1;
	int tmp = 0;
	scanf("%d %d %d", &x, &y, &z);
	while (x != 0 || y != 0 || z != 0) {
		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}
		if (y < z) {
			tmp = y;
			y = z;
			z = tmp;
		}
		if (x < y) {
			tmp = x;
			x = y;
			y = tmp;
		}
		printf("%d %d %d\n", x, y, z);
		scanf("%d %d %d", &x, &y, &z);
	}

	return 0;
}