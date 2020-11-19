#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input(int* p);
int* sel_next(int* p, int N, int M);
int number(int* p, int* q);

int main() {
	int N = 0, M = 0, size = 0, num = 0;
	int x[100] = { 0 };
	int* end = NULL;
	
	size = input(x);

	scanf("%d", &M);

	end = sel_next(x, size, M);

	num = number(x + M, end);

	printf("%d", num);

	return 0;
}

int input(int* p) {
	int* q = p;
	int cnt = 0;

	scanf("%d", q);
	while (*q != -1)
	{
		q++;
		cnt++;
		scanf("%d", q);
	}

	return cnt;
}

int* sel_next(int* p, int N, int M) {
	for (int* q = p + M; q < p + N; q++)
	{
		if (*q > * (q + 1))
			return q;
	}
}

int number(int* p, int* q) {
	int num = 0;

	for (int* k = p; k <= q; k++)
		num = num * 10 + *k;

	return num;
}