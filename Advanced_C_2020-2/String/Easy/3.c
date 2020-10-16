#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", result[101]="";
	int len = 0;

	scanf("%s", arr);

	while (arr[len])
		len++;

	for (int i = 0; i < len;i++)
	{
		for (int j = 0; j < len; j++)
		{
			result[j] = arr[(i + j) % len];
		}
		printf("%s\n", result);
	}

	return 0;
}