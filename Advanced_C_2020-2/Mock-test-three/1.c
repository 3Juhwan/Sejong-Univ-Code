#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(int* p, int N);
void output(int* p, int K);

int main() {
	int M = 0, N = 0, K = 0;
	int arr1[100] = { 0 }, arr2[100] = { 0 };
	int* p = arr1, * q = arr2;

	scanf("%d %d", &M, &N);
	
	input(arr1, M);
	input(arr2, N);

	scanf("%d", &K);

	while (p < arr1 + M || q < arr2 + N)
	{
		if (p < arr1 + M)
		{
			output(p, K);
			p += K;
		}
		if (q < arr2 + N)
		{
			output(q, K);
			q += K;
		}
	}

	return 0;
}

void input(int* p, int N) {
	for (int* q = p; q < p + N; q++)
		scanf("%d", q);
}

void output(int* p, int K) {
	for (int* q = p; q < p + K; q++)
		printf(" %d", *q);
}