#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", output[101]="";
	char* p = arr, * q = arr;
	int len = 0, max = 0;

	gets_s(arr, 101);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			len = strlen(q);
			if (max < len)
			{
				strcpy(output, q);
				max = len;
			}
			q += len + 1;
		}
		p++;
	}
	len = strlen(q);
	if (max < len)
		strcpy(output, q);
	
	printf("%s", output);

	return 0;
}