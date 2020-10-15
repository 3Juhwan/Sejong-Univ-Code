#pragma warning (disable:4996)
#include <stdio.h>

int add_to_k(int* p, int* q);

int main() {
	int N = 0,sum = 0, arr[100] = { 0, };
	int* p = NULL;

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
	while (p <= q)
	{
		sum += *p;
		p++;
	}
	return sum;
}