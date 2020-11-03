#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char* str; // 문자열 저장
	int cnt; // 자음 수 저장
	int num; // 숫자 저장
	int result; // 곱셈결과 저장
}st;

int main() {
	int N = 0, len = 0, tcnt = 0;
	char temp[101] = "";
	st* S = NULL, tmp = { "",0 };

	scanf("%d", &N);
	getchar();

	S = (st*)malloc(N * sizeof(st));

	if (S == NULL)
		return -1;

	for (int i = 0;i < N;i++)
	{
		tcnt = 0;
		scanf("%s", temp);
		getchar();

		len = strlen(temp);

		S[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (S[i].str == NULL)
			return -1;

		strcpy(S[i].str,temp);

		for (int j = 0;j < len;j++)
		{
			if (S[i].str[j] >= '0' && S[i].str[j] <= '9')
				S[i].num = S[i].str[j] - '0';
			else if (S[i].str[j] != 'A' && S[i].str[j] != 'E' && S[i].str[j] != 'I' && S[i].str[j] != 'O' && S[i].str[j] != 'U' && S[i].str[j] != 'a' && S[i].str[j] != 'e' && S[i].str[j] != 'i' && S[i].str[j] != 'o' && S[i].str[j] != 'u')
				tcnt++;
		}

		S[i].cnt = tcnt;
		S[i].result = tcnt * S[i].num;
	}

	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1;j++)
		{
			if (S[j].result < S[j + 1].result)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N;i++)
		printf("%s\n", S[i].str);

	for (int i = 0;i < N;i++)
		free(S[i].str);

	free(S);

	return 0;
}