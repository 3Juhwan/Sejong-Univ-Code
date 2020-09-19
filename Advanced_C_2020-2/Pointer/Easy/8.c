#pragma warning (disable:4996)
#include <stdio.h>

void swap(int* x, int* y);

int main() {
	int  N = 0, arr[50] = { 0, }, a = 0, b = 0;
	int* p = NULL;

	scanf("%d", &N);
	for (p = arr; p < arr + N;p++) scanf("%d", p);
	scanf("%d %d", &a, &b);

	swap(arr + a, arr + b);

	for (p = arr; p < arr + N;p++)
		printf(" %d", *p);

	return 0;
}

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}