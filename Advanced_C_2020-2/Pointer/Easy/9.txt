#pragma warning (disable:4996)
#include <stdio.h>

int* mid(int x[]);

int main() {
	int arr[3] = { 0, }, *p = NULL;

	for (p = arr;p < arr + 3;p++) scanf("%d", p);

	printf("%d", *mid(arr));

	return 0;
}

/* 중앙값은 나머지 두 수와의 차를 곱했을 때, 0보다 작거나 같다.
	예를 들어 1 7 9 일 경우, 중앙값은 7인데
	(7 - 1) * (7 - 9) = -12 로 0보다 작거나 같다.*/

int* mid(int x[]) {
	if ((*x - *(x + 1)) * (*x - *(x + 2)) <= 0) return x;
	else if ((*(x + 1) - *(x + 2)) * (*(x + 1) - *x) <= 0) return x + 1;
	else return x + 2;
}