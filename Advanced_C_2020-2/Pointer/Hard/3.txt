#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int N = 0, sum = 0;
	char str[100], *p = NULL, *q = NULL;

	scanf("%d", &N);
	getchar();

	for (p = str;p < str + N;p++)
	{
		scanf("%c", p);
	}

	for (p = str;p < str + N;p++)
	{
		// p 주소의 값이 문자일 때
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
		{
			printf("%c", *p);
		}

		// p 주소의 값이 숫자일 때
		else
		{
			int tmp = 0;
			for (q = p; *q >= '0' && *q <= '9';q++, p++)
			{
				tmp = tmp * 10 + (*q - '0');
			}
			sum += tmp;
			p--;
		}
	}

	printf("\n%d", sum);

	return 0;
}