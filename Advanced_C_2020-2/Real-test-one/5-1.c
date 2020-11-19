#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char letters[21];
	int count;
}word;

void count_word(struct word* W, int N);

int main() {
	int N = 0;
	word W[100] = { "" }, tmp = { "" };

	scanf("%d", &N);
	getchar();

	for (int i = 0;i < N;i++)
	{
		scanf("%s", W[i].letters);
		getchar();
		W[i].count = 0;
	}

	count_word(W, N);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (W[j].count < W[j + 1].count)
			{
				tmp = W[j];
				W[j] = W[j + 1];
				W[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d %s\n", W[i].count, W[i].letters);

	return 0;
}

void count_word(struct word* W, int N) {
	char vowel[11] = "AEIOUaeiou";
	word* p = W;

	for (p = W; p < W + N; p++)
		for (int i = 0; p->letters[i];i++)
			for (int j = 0; j < 10; j++)
				if (p->letters[i] == vowel[j])
					p->count++;
}
