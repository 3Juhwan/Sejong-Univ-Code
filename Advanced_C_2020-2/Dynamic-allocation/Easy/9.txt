#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, len = 0, mini_len = 101;
	char temp[101] = "";
	char** p = NULL, * mini_sen = NULL;

	scanf("%d", &N);
	getchar();

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL)
		return -1;

	for (int i = 0; i < N;i++)
	{
		gets(temp);
		len = strlen(temp);

		p[i] = (char*)malloc((len + 1) * sizeof(char));

		if (p[i] == NULL)
			return -1;

		strcpy(p[i], temp);

		if (len < mini_len)
		{
			mini_len = len;
			mini_sen = p[i];
		}
	}

	printf("%s", mini_sen);

	for (int i = 0; i < N;i++)
		free(p[i]);

	free(p);

	return 0;
}