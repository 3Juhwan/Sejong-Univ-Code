#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	int N = 0;
	char arr[10] = "", *p = arr;

	scanf("%d", &N);

	while (N > 0)
	{
		*p = N % 10 + '0';
		N /= 10;
		p++;
	}

	printf("%s", arr);

	return 0;
}