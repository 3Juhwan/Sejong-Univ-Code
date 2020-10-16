#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[81] = "", str2[11] = "";
	char* p = str1, * q = str2;
	int len1 = 0, len2 = 0, cnt = 0, is = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 0;i < len1; i++)
	{
		if (str1[i] == str2[0])
		{
			for (int j = 0; j < len2; j++)
			{
				if (str1[i + j] == str2[j])
					cnt++;
			}
		}
		if (cnt == len2)
			is++;
		cnt = 0;
	}

	if (is > 0)
		printf("%d %d", len1, 1);
	else
		printf("%d %d", len1, 0);

	return 0;
}