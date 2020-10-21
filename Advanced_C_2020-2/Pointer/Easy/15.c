#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

void ABC(int* p, int k);

int main() {
	int arr[10] = { 0, };
	int* p = arr;

	for (p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 9; p++)
		ABC(p, arr + 10 - p);

	for (p = arr; p < arr + 10; p++)
		printf(" %d", *p);

	return 0;
}

void ABC(int* p, int k) {
	int* q = p, * tmax = p, ttmp = 0;

	for (q = p + 1; q < p + k;q++)
		if (*tmax < *q)
			tmax = q;

	ttmp = *p;
	*p = *tmax;
	*tmax = ttmp;
}