#pragma warning (disable:4996)
#include <stdio.h>

int arrsum(int* p, int* q);

int main() {
	int N = 0, S = 0, E = 0;
	int arr[100] = { 0, };
	int* p = NULL;

	scanf("%d %d %d", &N, &S, &E);

	for (p = arr; p < arr + N;p++)
		scanf("%d", p);

	printf("%d", arrsum(arr + S, arr + E));

	return 0;
}

int arrsum(int* p, int* q) {
	int sum = 0;
	for (; p <= q; p++) sum += *p;
	return sum;
}