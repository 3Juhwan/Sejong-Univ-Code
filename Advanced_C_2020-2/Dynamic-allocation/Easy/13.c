#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, len = 0;
	char temp[101] = "";
	char** p = NULL, * tmp = NULL;

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
	}

	for (int i = 0; i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (strcmp(p[j], p[j+1]) >0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N;i++)
		printf("%s\n", p[i]);

	for (int i = 0; i < N;i++)
		free(p[i]);

	free(p);

	return 0;
}