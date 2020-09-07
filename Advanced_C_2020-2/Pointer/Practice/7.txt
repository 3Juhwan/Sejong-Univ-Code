#pragma warning (disable:4996)
#include <stdio.h>

void input(int* x, int* y, int* z);
void output(int *x, int* y,int* z);

int main() {
	int x = 0, y = 0, z = 0;

	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

void input(int* x, int* y, int* z) {
	scanf("%d %d %d", x, y, z);
}

void output(int* x, int* y, int* z) {
	printf("%d %d %d", *x, *y, *z);
}