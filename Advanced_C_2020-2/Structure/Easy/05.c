#pragma warning (disable:4996)
#include <stdio.h>

struct Student {
	char name[9];
	int kor;
	int eng;
	int math;
	double avg;
	char grade;
};

int main() {
	struct Student S[50] = { '\0', }, *p = NULL;
	int N = 0;

	scanf("%d", &N);
	for (p = S; p < S + N; p++)
	{
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
		p->avg = (p->kor + p->eng + p->math)/  3.0;

		if (p->avg >= 90)
			p->grade = 'A';
		else if (p->avg >= 80)
			p->grade = 'B';
		else if (p->avg >= 70)
			p->grade = 'C';
		else
			p->grade = 'D';
	}

	for (p = S; p < S + N; p++)
			printf("%s %.1lf %c\n", p->name, p->avg, p->grade);

	return 0;
}