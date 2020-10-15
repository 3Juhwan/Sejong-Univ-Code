#pragma warning (disable:4996)
#include <stdio.h>

void gcdlcm(int x, int y, int* p, int* q);

int main() {
	int x = 0, y = 0, max = 0, min = 0;

	scanf("%d %d", &x, &y);

	gcdlcm(x, y, &max, &min);

	printf("%d %d", max, min);

	return 0;
}

void gcdlcm(int x, int y, int* p, int* q) {
	int flag = x > y ? y : x;

	while (flag > 0)
	{
		if (x % flag == 0 && y % flag == 0)
			break;
		flag--;
	}
	*p = flag;
	*q = x * y / flag;
}