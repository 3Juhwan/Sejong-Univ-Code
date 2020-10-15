#pragma warning (disable:4996)
#include <stdio.h>

void ABC(int* S, int k);

int main() {
	int arr[10] = { 0, };
	int* p = NULL;

	for (p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 10;p++)
		ABC(p, arr + 10 - p);

	for (p = arr; p < arr + 10; p++)
		printf(" %d", *p);

	return 0;
}

void ABC(int* S, int k) {
	int* max = S, tmp = *S;
	for (int* p = S; p < S + k;p++)
		if (*max < *p)
			max = p;
	tmp = *S;
	*S = *max;
	*max = tmp;
}