#pragma warning (disable:4996)
#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

struct date* select_min(struct date *x, struct date *y);

int main() {
	struct date D1 = { 0 }, D2 = { 0 }, *p = NULL;

	scanf("%d/%d/%d", &D1.year, &D1.month, &D1.day);
	scanf("%d/%d/%d", &D2.year, &D2.month, &D2.day);

	p = select_min(&D1, &D2);

	printf("%d/%d/%d", p->year, p->month, p->day);

	return 0;
}

struct date* select_min(struct date* x, struct date* y) {
	if (x->year == y->year)
	{
		if (x->month == y->month)
		{
			if (x->day >= y->day)
				return y;
			else
				return x;
		}
		else if (x->month > y->month)
			return y;
		else
			return x;
	}
	else if (x->year > y->year)
		return y;
	else
		return x;
}