#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", result[101] = "";
	int N = 0, min = 101, len = 0;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N;i++)
	{
		gets(arr);
		len = strlen(arr);

		if (min > len) {
			strcpy(result, arr);
			min = len;
		}
	}

	printf("%s", result);

	return 0;
}