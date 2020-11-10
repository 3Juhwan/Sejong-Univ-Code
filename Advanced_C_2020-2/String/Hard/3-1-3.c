#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr1[101] = "", arr2[101] = "";
	char* p = arr1;
	int cnt = 0, len = 0;

	gets(arr1);
	gets(arr2);
	len = strlen(arr2);

	while (*(p + len - 1))
	{
		if (strncmp(p, arr2, len) == 0)
			cnt++;
		p++;
	}

	printf("%d", cnt);

	return 0;
}