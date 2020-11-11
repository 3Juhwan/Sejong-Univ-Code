#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[31];
	int grade;
	double reputation;
	double distance;
	char meal;
}hotel_info;

int in_hotel_info(hotel_info* p);
void out_hotel_info(hotel_info* p, int N, int G, double D);

int main() {
	hotel_info H[100] = { "" };
	int size = 0, G = 0;
	double D = 0.0;

	size = in_hotel_info(H);

	scanf("%d %lf", &G, &D);

	out_hotel_info(H, size, G, D);

	return 0;
}

int in_hotel_info(hotel_info* p) {
	hotel_info* q = p;
	int size = 0;

	scanf("%s", q->name);
	while (strcmp(q->name, "0") != 0)
	{
		scanf("%d %lf %lf %c", &q->grade, &q->reputation, &q->distance, &q->meal);
		getchar();
		size++;
		q++;

		scanf("%s", q->name);
	}

	return size;
}

void out_hotel_info(hotel_info* p, int N, int G, double D) {
	hotel_info tmp = { "" };

	for (hotel_info* q = p; q < p + N - 1; q++)
	{
		for (hotel_info* r = q + 1; r < p + N; r++)
		{
			if (r->reputation > q->reputation || (r->reputation == q->reputation && strcmp(r->name, q->name) < 0))
			{
				tmp = *r;
				*r = *q;
				*q = tmp;
			}
		}
	}

	for (hotel_info* q = p; q < p + N; q++)
		if (q->grade >= G && q->distance <= D)
			printf("%s %d %.1lf %.1lf %c\n", q->name, q->grade, q->reputation, q->distance, q->meal);
}