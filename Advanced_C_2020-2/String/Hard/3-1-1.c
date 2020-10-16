#pragma warning (disable:4669)
#include <stdio.h>
#include <string.h>

char* search(char arr1[], char arr2[]);

int main() {
	char arr1[100] = "", arr2[100] = "";
	char* p = arr1;
	int cnt = 0;

	gets_s(arr1, 100);
	gets_s(arr2, 100);
		
	p = search(p, arr2);

	while (p)
	{
		cnt++;
		p = search(p + strlen(arr2), arr2);
	}
	printf("%d\n", cnt);

	return 0;
}

char* search(char arr1[], char arr2[]) {
	int len1 = 0, len2 = 0;
	char* p = arr1;

	len1 = strlen(arr1);
	len2 = strlen(arr2);

	for (p = arr1; p <= arr1 + len1 - len2; p++)
	{
		if (strncmp(p, arr2, len2) == 0)
			return p;
	}
	return NULL;
}