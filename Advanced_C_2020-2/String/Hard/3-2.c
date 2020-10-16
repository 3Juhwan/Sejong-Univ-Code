#pragma warning (disable:4669)
#include <stdio.h>
#include <string.h>

int main() {
	char arr1[100] = "", arr2[100] = "";
	char* p = arr1;
	int len = 0, cnt = 0;

	gets_s(arr1, 100);
	gets_s(arr2, 100);

	len = strlen(arr1);

	while (*p)
	{
		if (*p == ' ' || *p == '.')
			*p = '\0';
		p++;
	}

	p = arr1;
	while (p < arr1 + len)
	{
		if (strcmp(p, arr2) == 0)
			cnt++;
		p += strlen(p) + 1;
	}

	printf("%d\n", cnt);


	return 0;
}