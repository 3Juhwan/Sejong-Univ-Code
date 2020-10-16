#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr1[100] = "", arr2[100] = "", * p = arr1, * q = arr2, *r = NULL;
	int cnt = 0, len2 = 0, total = 0;

	gets_s(arr1, 100);
	gets_s(arr2, 100);

	len2 = strlen(arr2);

	while (*p)
	{
		for (q = arr2, r = p; *q == *r && *q; q++, r++)
			cnt++;
		if (cnt == len2)
			total++;
		cnt = 0;
		p++;
	}

	printf("%d", total);

	return 0;
}