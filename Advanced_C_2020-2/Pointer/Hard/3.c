#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int N = 0, sum = 0, tmp = 0, size = 0;
	char arr[100] = "", narr[100] = "", * p = NULL, * q = narr;

	scanf("%d", &N);
	getchar();
	for (p = arr; p < arr + N;p++)
		scanf("%c", p);

	p = arr;
	while (p < arr + N)
	{
		if (*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z')
		{
			*q = *p;
			q++;
			size++;
		}
		else if (*p >= '0' && *p <= '9')
		{
			while (*p >= '0' && *p <= '9')
			{
				tmp = tmp * 10 + (*p - '0');
				p++;
			}
			sum += tmp;
			tmp = 0;
			p--;
		}
		p++;
	}

	for (p = narr; p < narr + size;p++)
		printf("%c", *p);
	printf("\n%d", sum);

	return 0;
}