#pragma warning (disable:4996)
#include <stdio.h>

struct Student {
	int gender;
	int weight;
	int height;
};

int man(struct Student p);
int woman(struct Student p);

int main() {
	struct Student S[10] = { '\0', };
	int N = 0, grade[3] = { 0, }, tmp = 0;

	scanf("%d", &N);
	for (int i = 0;i < N;i++)
		scanf("%d %d %d", &S[i].gender, &S[i].weight, &S[i].height);

	for (int i = 0; i < N; i++)
	{
		if (S[i].gender == 1)
			tmp = man(S[i]) - 1;
		else if (S[i].gender == 2)
			tmp = woman(S[i]) - 1;
		grade[tmp]++;
	}
	printf("%d %d %d", grade[0], grade[1], grade[2]);

	return 0;
}

int man(struct Student p) {
	if (p.height >= 175) 
	{
		if (p.weight >= 70)
			return 1;
		else if (p.weight >= 60)
			return 2;
		else
			return 3;
	}
	else if (p.height >= 165) 
	{
		if (p.weight >= 70)
			return 3;
		else if (p.weight >= 60)
			return 1;
		else
			return 2;
	}
	else 
	{
		if (p.weight >= 70)
			return 2;
		else if (p.weight >= 60)
			return 3;
		else
			return 1;
	}
}

int woman(struct Student p) {
	if (p.height >= 175)
	{
		if (p.weight >= 60)
			return 1;
		else if (p.weight >= 50)
			return 2;
		else
			return 3;
	}
	else if (p.height >= 165)
	{
		if (p.weight >= 60)
			return 3;
		else if (p.weight >= 50)
			return 1;
		else
			return 2;
	}
	else
	{
		if (p.weight >= 60)
			return 2;
		else if (p.weight >= 50)
			return 3;
		else
			return 1;
	}
}