#pragma warning (disable:4996)
#include <stdio.h>

void input(int* p, int* q, int* r);
void output(int* p, int* q, int* r);

int main() {
	int x = 0, y = 0, z = 0;

	input(&x, &y, &z);
	output(&x, &y, &z);

	return 0;
}

void input(int* p, int* q, int* r) {
	scanf("%d %d %d", p, q, r);
}

void output(int* p, int* q, int* r) {
	printf("%d %d %d", *p, *q, *r);
}