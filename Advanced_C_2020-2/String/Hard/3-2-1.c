#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", cmp[101]="";
	char* p = arr, * q = arr;
	int cnt = 0;

	gets_s(arr, 101);
	gets_s(cmp, 101);

	if (strcmp(cmp, q) == 0)
		cnt++;
	while (*p)
	{
		if (*p == ' ' || *p == '.')
		{
			*p = '\0';
			if (strcmp(cmp, q) == 0)
				cnt++;

			q += strlen(q) + 1;
		}
		p++;
	}
	if (strcmp(cmp, q) == 0)
		cnt++;

	printf("%d", cnt);

	return 0;
}