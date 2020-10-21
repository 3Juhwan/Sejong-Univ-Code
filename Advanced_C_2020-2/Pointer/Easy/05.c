#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int arr[5] = { 0, }, rank[5] = { 1,1,1,1,1 };	// 아래 비교하는 코드에서 등호가 빠졌기 때문에, 1로 초기화
	int* p = NULL, *q = NULL, *r = NULL;

	for (p = arr; p < arr + 5; p++)
		scanf("%d", p);

	// 자신보다 클 경우, rank에 1을 더한다.
	for (p = arr, r = rank; p < arr + 5;p++, r++) 
		for (q = arr;q < arr + 5;q++) 
			if (*p < *q)++* r;

	for (p = arr, r = rank; p < arr + 5;p++, r++)
		printf("%d=r%d ", *p, *r);

	return 0;
}