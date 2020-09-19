#pragma warning (disable:4996)
#include <stdio.h>

void ABC(int* p, int k);

int main() {
	int arr[10] = { 0, };
	int* p = NULL;

	for (p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 10; p++)
		ABC(p, arr + 10 - p);

	for (p = arr; p < arr + 10; p++)
		printf(" %d", *p);

	return 0;
}

void ABC(int* x, int k) {
	int *p = NULL, * max = x, tmp = 0;		// max에 최대값의 주소를 저장, tmp를 이용해서 swap한다
	
	for (p = x;p < x + k;p++)
		if (*max < *p)max = p;

	tmp = *max;
	*max = *x;
	*x = tmp;
}