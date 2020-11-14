#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* str; // 문자열 저장
	int cnt; // 자음 수 저장
}st;

int main() {
	int N = 0, len = 0, tcnt = 0;
	char temp[101] = "", ch = '\0';
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
			ch = S[i].str[j];
			if (ch != 'a' && ch != 'A' && ch != 'e' && ch != 'E' && ch != 'i' && ch != 'I' && ch != 'o' && ch != 'O' && ch != 'u' && ch != 'U')
				tcnt++;
		}
		S[i].cnt = tcnt;
	}

	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1;j++)
		{
			if (S[j].cnt < S[j + 1].cnt)
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
		if (S[i].str != NULL)
			free(S[i].str);
	
	if (S != NULL)
	free(S);

	return 0;
}