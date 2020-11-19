#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	int stnum;
	int s1;
	int s2;
	double avg;
}student;

int main() {
	int N = 0, cut_line_1 = 0, cut_line_2 = 0, cnt = 0;
	student* p = NULL, tmp = { 0 };

	scanf("%d", &N);
	getchar();

	cut_line_1 = (int)(N * 0.6);
	cut_line_2 = (int)(N * 0.8);

	p = (student*)malloc(N * sizeof(student));
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	// input
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &p[i].stnum, &p[i].s1, &p[i].s2);
		p[i].avg = p[i].s1 * 0.4 + p[i].s2 * 0.6;
	}

	// sorting by avg
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (p[j].avg < p[j + 1].avg)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (int i = cut_line_1 - 1; p[i].avg == p[i + 1].avg;i++)
		cut_line_1++;

	for (int i = cut_line_1; i < N - 1; i++)
	{
		for (int j = cut_line_1; j < N - 1 - (i - cut_line_1);j++)
		{
			if (p[j].s2 < p[j + 1].s2)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (int i = cut_line_2 - 1; p[i].s2 == p[i + 1].s2;i++)
		cut_line_2++;

	for (int i = 0; i < cut_line_2; i++)
	{
		for (int j = 0; j < cut_line_2 - i - 1;j++)
		{
			if (p[j].stnum > p[j + 1].stnum)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < cut_line_2; i++)
		printf("%d\n", p[i].stnum);

	free(p);

	return 0;
}