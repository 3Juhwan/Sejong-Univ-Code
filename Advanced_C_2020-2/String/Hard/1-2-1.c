#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

void convert(char arr[], char result[], int N );

int main() {
	char arr1[21] = "", arr2[21] = "", cstr[201] = "";
	int cnt = 0;

	gets_s(arr1, 21);
	gets_s(arr2, 21);

	for (int i = 1; i <= 10;i++)
	{
		convert(arr1, cstr, i);
		if (strcmp(arr2, cstr) == 0)
			cnt += 1;

		convert(arr2, cstr, i);
		if (strcmp(arr1, cstr) == 0)
			cnt += 2;
	}

	printf("%d", cnt);

	return 0;
}

void convert(char arr[], char result[], int N) {
	int i = 0, j = 0, k = 0, M = 0;
	int len = strlen(arr);

	for (i = 0; i < len; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			result[j] = arr[i] + N;
			j++;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			result[j] = arr[i] - N;
			j++;
		}
		else if (arr[i] >= '0' && arr[i] <= '9')
		{
			M = arr[i] - '0';
			while (i + 1 < len && arr[i + 1] >= '0' && arr[i + 1] <= '9')
			{
				M = M * 10 + arr[i + 1] - '0';
				i++;
			}
			for (k = 0; k < N;k++)
			{
				result[j] = M + 'A' - 1;
				j++;
			}
		}
		else
		{
			result[j] = ' ';
			j++;
		}
	}
}