#pragma warning (disable:4996)
#include <stdio.h>

void swap(int* p, int* q);

int main() {
	int N = 0, a = 0, b = 0, arr[50] = { 0, };

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d", &a, &b);

	swap(&arr[a], &arr[b]);

	for (int i = 0; i < N; i++)
		printf(" %d", arr[i]);

	return 0;
}

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}