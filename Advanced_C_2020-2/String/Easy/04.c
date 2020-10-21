#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[101] = "", str2[101] = "";
	char* p = str1, * q = str2;
	int len1 = 0, len2 = 0, idx = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	while (*p) {
		len1++;
		p++;
	}
	while (*q) {
		len2++;
		q++;
	}
	p = str1;
	q = str2;

	while (*p == *q && *p) {
		idx++;
		p++;
		q++;
	}

	if (idx == len1 && len1 == len2)
		printf("%d %d", len1, 1);
	else
		printf("%d %d", len1, 0);

	return 0;
}