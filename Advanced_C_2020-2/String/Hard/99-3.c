#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

// 여러 문자열 입력 받고 사전순으로 출력
int main() {
	char arr[100][101] = {""}, tmp[101] = "";
	int N = 0;
	int cmp = 0;

	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets_s(arr[i], 101);
		for (int j = 0; j < i;j++)
		{
			if (strcmp(arr[i], arr[j]) < 0)
			{
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp);
			}
		}
	}
	for (int i = 0; i < N; i++)
		printf("%s\n", arr[i]);

	return 0;
}