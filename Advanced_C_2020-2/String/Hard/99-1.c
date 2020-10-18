#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

// 여러 문자열 입력 받고 길이 내림차순으로 출력
int main() {
	char arr[100][101] = {""}, tmp[101] = "";
	int N = 0;
	int len1 = 0, len2 = 0;

	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets_s(arr[i], 101);
		for (int j = 0; j < i;j++)
		{
			len1 = strlen(arr[i]);
			len2 = strlen(arr[j]);
			if (len1 < len2)
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