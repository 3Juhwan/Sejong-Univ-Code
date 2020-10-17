#pragma warning (disable:4996)
#include <stdio.h>

struct student {
	int high;
	int low;
	char flag;
	int stddif;
	int dif;
};

void passorfail(struct student* p);

int main() {
	struct student result = { 0 };

	scanf("%d %d %d", &result.high, &result.low, &result.stddif);

	passorfail(&result);

	printf("%d %c", result.dif, result.flag);

	return 0;
}

void passorfail(struct student* p) {
	p->dif = (p->high - p->low);
	if (p->stddif >= p->dif)
		p->flag = 'P';
	else
		p->flag = 'F';
}