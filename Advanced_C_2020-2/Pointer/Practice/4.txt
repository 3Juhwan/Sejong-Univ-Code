#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int arr[3] = { 0, }, * p = NULL;

	for (p = arr; p < arr + 3;p++) scanf("%d", p);

	p = arr;

	/* 중앙값은 나머지 두 수와의 차를 곱했을 때, 0보다 작거나 같다.
		예를 들어 1 7 9 일 경우, 중앙값은 7인데
		(7 - 1) * (7 - 9) = -12 로 0보다 작거나 같다.*/

	if ((*p - *(p + 1)) * (*p - *(p + 2)) <= 0) printf("%d", *p);
	else if ((*(p + 1) - *(p + 2)) * (*(p + 1) - *p) <= 0) printf("%d", *(p + 1));
	else printf("%d", *(p + 2));

	return 0;
}