#pragma warning (disable:4996)
#include <stdio.h>

struct student {
	char name[10];
	int score;
};

struct student* select_min(struct student x[]);

int main() {
	struct student D[5] = { 0 }, *p = NULL;

	for (int i = 0; i < 5; i++)
		scanf("%s %d", D[i].name, &D[i].score);

	p = select_min(D);

	printf("%s %d", p->name, p->score);

	return 0;
}

struct student* select_min(struct student x[]) {
	struct student *min= x;

	for (int i = 0;i < 5;i++)
		if (min->score > x[i].score)
			min = &x[i];

	return min;
}