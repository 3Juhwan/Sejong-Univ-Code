#pragma warning (disable:4996)
#include <stdio.h>

void gcdlcm(int x, int y, int* p, int* q);

int main() {
	int a = 0, b = 0;

	scanf("%d %d", &a, &b);

	gcdlcm(a, b, &a, &b);

	printf("%d %d", a, b);

	return 0;
}

void gcdlcm(int x, int y, int* p, int* q) {
	int  i = x > y ? y : x;				// x와 y 중에 더 작은 값으로 i를 초기화한다

	for (;x % i != 0 || y % i != 0;i--)
		;
	*p = i;
	*q = x * y / i;
}