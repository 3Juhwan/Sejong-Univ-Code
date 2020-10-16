#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	char arr[1000] = "";
	char endsmb = '\0';
	char* p = arr, *q = NULL, *r = NULL;

	scanf("%c", p);
	while (*p != '.' && *p != '?' && *p != '!')
	{
		p++;
		scanf("%c", p);
	}

	endsmb = *p;
	q = p;

	while (p >= arr)
	{
		while (*p != ' ' && p >= arr)
			p--;

		r = p + 1;
		while (r < q)
		{
			printf("%c", *r);
			r++;
		}

		if (p > arr)
			printf(" ");

		q = p;
		p--;
	}
	printf("%c", endsmb);

	return 0;
}