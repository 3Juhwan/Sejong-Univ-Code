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
void print_money(STUDENT p[], int N, int M);

int main() {
	STUDENT* p = NULL, tmp = { "" };
	int N = 0, cnt = 0, n = 1, select_num = 0;

	scanf("%d", &N);
	getchar();

	p = (STUDENT*)malloc(N * sizeof(STUDENT));
	if (p == NULL)
		return -1;

	input(p, N);
	sorting(p, N);
	cnt = search_deny(p, N);
	//print_denied(p, N, cnt);	

	scanf("%d", &select_num);

	print_money(p, N, select_num);

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

void print_money(STUDENT p[], int N, int M) {
	STUDENT* s_st = NULL;
	int n = 0, time = 0, money = 0;

	for (int i = 0;i < M;i++)
	{
		scanf("%d", &n);

		for (int j = 0;j < N;j++)
			if (n == atoi(p[j].carNum))
				s_st = &p[j];

		if (s_st->deny)
		{
			printf("100000\n");
			continue;
		}

		time = time_calculate(s_st);

		if (time <= 60)
			money = 3000;
		else if (time >= 321)
			money = 30000;
		else
			money = 3000 + 1000 * ((time - 60) / 10 + 1);

		printf("%d\n", money);
	}
}

int time_calculate(STUDENT* p) {
	int t_from = 0, t_to = 0, time = 0;

	t_from = ((p->Stime[0] - '0') * 10 + (p->Stime[1] - '0')) * 60 + (p->Stime[3] - '0') * 10 + (p->Stime[4] - '0');
	t_to = ((p->Etime[0] - '0') * 10 + (p->Etime[1] - '0')) * 60 + (p->Etime[3] - '0') * 10 + (p->Etime[4] - '0');
	time = t_to - t_from;

	return time;
}