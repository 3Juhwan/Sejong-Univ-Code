#pragma warning (disable:4996)
#include <stdio.h>

void addArray(int a[], int b[], int c[], int N);

int main() {
	int a[20] = { 0, }, b[20] = { 0, }, c[20] = { 0, };
	int N = 0, * p = NULL;

	scanf("%d", &N);
	for (p = a;p < a + N;p++)
		scanf("%d", p);
	for (p = b;p < b + N;p++)
		scanf("%d", p);

	addArray(a, b, c, N);

	for (p = c; p < c + N; p++)
		printf(" %d", *p);

	return 0;
}

void addArray(int a[], int b[], int c[], int N) {
	for (int i = 0; i < N; i++)
		*(c + i) = *(a + i) + *(b + N - i - 1);
}