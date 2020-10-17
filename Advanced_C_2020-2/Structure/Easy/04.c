#pragma warning (disable:4996)
#include <stdio.h>

struct Student {
	char name[20];
	int score[3];
	double avg;
	char grade;
};

int main() {
	struct Student S[20] = { '\0', };
	int N = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", S[i].name, &S[i].score[0], &S[i].score[1], &S[i].score[2]);
		S[i].avg = (S[i].score[0] + S[i].score[1] + S[i].score[2])/  3.0;

		if (S[i].avg >= 90)
			S[i].grade = 'A';
		else if (S[i].avg >= 80)
			S[i].grade = 'B';
		else if (S[i].avg >= 70)
			S[i].grade = 'C';
		else
			S[i].grade = 'F';
	}

	for (int i = 0;i < N;i++)
			printf("%s %.1lf %c\n", S[i].name, S[i].avg, S[i].grade);

	return 0;
}