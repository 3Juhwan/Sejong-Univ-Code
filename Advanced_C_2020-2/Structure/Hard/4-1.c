#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char carNum[5];
	char stNum[7];
	char Sdate[11];
	char Stime[6];
	char Edate[11];
	char Etime[6];
	int deny;
}STUDENT;

void input(STUDENT p[], int N);
void sorting(STUDENT p[], int N);
int search_deny(STUDENT p[], int N);
void print_denied(STUDENT p[], int N, int cnt);

int main() {
	STUDENT* p = NULL, tmp = { "" };
	int N = 0, cnt = 0, n = 1;

	scanf("%d", &N);
	getchar();

	p = (STUDENT*)malloc(N * sizeof(STUDENT));
	if (p == NULL)
		return -1;

	input(p, N);
	sorting(p, N);
	cnt = search_deny(p, N);
	print_denied(p, N, cnt);	

	free(p);

	return 0;
}

void input(STUDENT p[], int N) {
	for (int i = 0; i < N;i++)
	{
		scanf("%s %s %s %s %s %s", p[i].carNum, p[i].stNum, p[i].Sdate, p[i].Stime, p[i].Edate, p[i].Etime);
		getchar();

		p[i].deny = 0;
	}
}

void sorting(STUDENT p[], int N) {
	STUDENT tmp;
	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (strcmp(p[j].stNum, p[j + 1].stNum) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

int search_deny(STUDENT p[], int N) {
	int cnt = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (strcmp(p[i].stNum, p[i + 1].stNum) == 0)
		{
			if (p[i].deny)
				p[i + 1].deny = p[i].deny;
			else
			{
				p[i].deny = cnt;
				p[i + 1].deny = cnt;
				cnt++;
			}
		}
	}
	
	return cnt;
}

void print_denied(STUDENT p[], int N, int cnt) {
	int n = 1;

	while (n < cnt)
	{
		for (int j = 0; j < N;j++)
		{
			if (p[j].deny == n)
			{
				printf("%s\n", p[j].stNum);
				n++;
				break;
			}
		}
	}
}