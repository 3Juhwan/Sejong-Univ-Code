#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char str[101], *p = str, *q = str;
	int N = 0, cnt = 0;

	gets_s(str, 101);
	scanf("%d", &N);

	while (*p)
	{
		if (*p == ' ')
		{
			cnt++;
			*p = '\0';

			if (cnt == N)
			{
				printf("%s", q);
				break;
			}
			q += strlen(q) + 1;
		}
		p++;
	}
	cnt++;
	if (cnt == N)
		printf("%s", q);

	return 0;
}