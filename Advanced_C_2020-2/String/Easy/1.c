#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char arr[21] = "", * p = arr;

	scanf("%s", arr);

	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
			printf("%c", *p);
		p++;
	}

	return 0;
}