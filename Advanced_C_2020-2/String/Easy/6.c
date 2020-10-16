#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[41] = "", str2[41] = "";
	char* p = str1, * q = str2;
	int N = 0,ad = 0, len1 = 0, len2 = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &N);
	scanf("%d", &ad);

	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;

	for (int i = len1 - 1;i >= N; i--)
		str1[i + len2] = str1[i];

	if (ad)
	{
		for (int i = 0;i < len2; i++)
			str1[i + N] = str2[len2 - i - 1];
	}
	else
	{
		for (int i = 0;i < len2; i++)
			str1[i + N] = str2[i];
	}

	printf("%s", str1);

	return 0;
}