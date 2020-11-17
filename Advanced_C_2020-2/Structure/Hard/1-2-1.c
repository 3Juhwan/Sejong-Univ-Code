#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st {
	char* str;
	int cnt;
	int num;
	int result;
}st;

// 모음 카운트
int count_c(char* ch);

int main() {
	int N = 0, len = 0, v_cnt = 0;
	char temp[101] = "";
	char* p = NULL;
	st* S = NULL, tmp = { NULL };

	scanf("%d", &N);
	getchar();

	S = (st*)malloc(N * sizeof(st));
	if (S == NULL) {
		printf("Insufficient Memory");
		return -1;
	}

	for (int i = 0; i < N;i++)
	{
		gets_s(temp, 101);
		len = strlen(temp);

		S[i].str = (char*)malloc((len + 1) * sizeof(char));
		if (S[i].str == NULL) {
			printf("Insufficient Memory");
			return -1;
		}

		strcpy(S[i].str, temp);

		p = S[i].str;
		while (*p)
		{
			if (*p >= '0' && *p <= '9')
				S[i].num = *p - '0';
			p++;
		}
		S[i].cnt = strlen(S[i].str) - count_c(S[i].str) - 1;
		S[i].result = S[i].cnt * S[i].num;

		v_cnt = 0;
	}

	for (int i = 0; i < N - 1; i++)
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


	for (int i = 0; i < N; i++)
		free(S[i].str);

	free(S);

	return 0;
}

int count_c(char* ch) {
	char vowel[11] = "aeiouAEIOU";
	int cnt = 0;

	for (int i = 0;i < strlen(ch);i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ch[i] == vowel[j])
			{
				cnt++;
				break;
			}
		}
	}

	return cnt;
}