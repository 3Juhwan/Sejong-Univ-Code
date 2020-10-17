#pragma warning (disable:4996)
#include <stdio.h>

struct Student {
	char name[10];
	int score;
};

int main() {
	struct Student S[5] = { '\0', };
	double avg = 0.0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", S[i].name, &S[i].score);
		avg += S[i].score;
	}
	avg /= 5.0;

	for (int i = 0;i < 5;i++)
		if (S[i].score <= avg)
			printf("%s\n", S[i].name);

	return 0;
}