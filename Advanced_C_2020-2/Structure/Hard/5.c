#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[31];
	char stnum[9];
	int subnum;
	char subname[10][31];
	double score[10];
	double avg;
}Stud;

int insert(Stud* p, int N);
void sort(Stud* p, int N);
void print_s(Stud* p, int N);
int delete(Stud* p, int N);
void print(Stud* p, int N);

int main() {
	int cnt = 0;
	char input = '\0';
	Stud S[100] = { "" };

	scanf("%c", &input);
	getchar();
	while (input != 'Q')
	{
		switch (input)
		{
		case 'I':
			cnt = insert(&S[cnt], cnt);
			break;
		case 'S':
			sort(S, cnt);
			break;
		case 'D':
			cnt = delete(S, cnt);
			break;
		case 'P':
			print(S, cnt);
			break;
		case 'Q':
			break;
		default:
			break;
		}

		scanf("%c", &input);
		getchar();
	}

	return 0;
}

int insert(Stud* p, int N) {
	int cnt = 0;

	scanf("%s %s %d ", p->name, p->stnum, &p->subnum);
	getchar();

	cnt = p->subnum;
	p->avg = 0;

	for (int i = 0; i < cnt;i++)
	{
		scanf("%s %lf", p->subname[i], &p->score[i]);
		getchar();
		p->avg += p->score[i];
	}

	p->avg /= cnt;

	return N + 1;
}

void sort(Stud* p, int N) {
	Stud S[100] = { "" };

	for (int i = 0; i < N; i++)
		S[i] = p[i];

	print_s(S, N);
}

void print_s(Stud* p, int N) {
	Stud tmp = { "" };

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N - i - 1;j++)
		{
			if (strcmp(p[j].name, p[j + 1].name) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}

	for(int i =0;i<N;i++)
		printf("%s %s %d %.2lf\n", p[i].name, p[i].stnum, p[i].subnum, p[i].avg);
}

int delete(Stud* p, int N) {
	char input_name[31] = "";
	int flag = 0;

	gets_s(input_name, 31);

	for (int i = 0; i < N; i++)
	{
		if (strcmp(input_name, p[i].name) == 0)
		{
			for (int j = i;j < N;j++)
				p[j] = p[j + 1];
			flag++;
			break;
		}
	}

	if (flag)
		return N - 1;
	else
		return N;
}

void print(Stud* p, int N) {
	for (int i = 0; i < N;i++)
		printf("%s %s %d %.2lf\n", p[i].name, p[i].stnum, p[i].subnum, p[i].avg);
}