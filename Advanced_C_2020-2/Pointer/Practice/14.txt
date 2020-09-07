#pragma warning (disable:4996)
#include <stdio.h>

int add_to_k(int* p, int* q);

int main() {
	int N = 0, sum = 0, *p = NULL;
	int arr[100] = { 0, };

	scanf("%d", &N);

	for (p = arr; p < arr + N; p++)
		scanf("%d", p);

	for (p = arr; p < arr + N; p++)
		sum += add_to_k(arr, p);

	printf("%d", sum);

	return 0;
}

int add_to_k(int* p, int* q) {
	int sum = 0;
	for (;p <= q;p++) sum += *p;
	return sum;
}