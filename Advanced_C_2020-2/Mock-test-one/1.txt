#pragma warning (disable:4996)
#include <stdio.h>

void input(int* p, int M);
int* sel_max(int* p, int M);
void output(int* p, int N);

int main(void) {
	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}

	output(out, N);

	return 0;
}

void input(int* p, int M) {
	for (int* q = p; q < p + M; q++)
		scanf("%d", q);
}

int* sel_max(int* p, int M) {
	int cnt = 0, mcnt = 0;
	int* pm = NULL;

	for (int* q = p; q < p + M; q++)
	{
		for (int* r = q; r < p + M; r++)
		{
			if (*q == *r)
				cnt++;
		}
		if (mcnt < cnt)
		{
			pm = q;
			mcnt = cnt;
		}
		cnt = 0;
	}
	return pm;
}

void output(int* p, int N) {
	for (int* q = p; q < p + N; q++)
		printf(" %d", *q);
}