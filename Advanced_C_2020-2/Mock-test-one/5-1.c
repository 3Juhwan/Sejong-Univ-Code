#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct st {
	char name[51];
	char id[8];
}st;

int main() {
	int N = 0;
	st* S = NULL, tmp = { "" };

	scanf("%d", &N);
	getchar();

	S = (st*)malloc(N * sizeof(st));
	if (S == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
	{
		gets_s(S[i].name, 51);
		gets_s(S[i].id, 8);
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (strcmp(S[j].name, S[j + 1].name) > 0)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
			else if (strcmp(S[j].name, S[j + 1].name) == 0 && strcmp(S[j].id, S[j + 1].id) > 0)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%s %s\n", S[i].name, S[i].id);

	return 0;
}