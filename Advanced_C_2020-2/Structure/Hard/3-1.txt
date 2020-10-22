#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

struct hotel_info {
	char name[31];
	int grade;
	double reput;
	double distance;
	char meal;
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main() {
	struct hotel_info hotel[100] = { '\0' }, * p = hotel;
	int hotel_num = 0;
	int G = 0;
	double D = 0;

	hotel_num = in_hotel_info(hotel);

	scanf("%d %lf", &G, &D);

	out_hotel_info(hotel, hotel_num, G, D);

	return 0;
}

int in_hotel_info(struct hotel_info* p) {
	struct hotel_info* q = p;
	int cnt = 0;

	scanf("%s", q->name);
	while (strcmp(q->name, "0"))
	{
		scanf("%d %lf %lf %c", &q->grade, &q->reput, &q->distance, &q->meal);
		getchar();
		q++;
		cnt++;
		scanf("%s", q->name);
	}
	return cnt;
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D) {
	struct hotel_info* q = p, tmp;
	double max = 0.0;

	for (q = p; q < p + N; q++)
	{
		if (q->distance <= D && q->grade >= G)
		{
			if (q->reput > max || (q->reput == max && strcmp(tmp.name, q->name)) > 0)
			{
				max = q->reput;
				tmp = *q;
			}
		}
	}
	printf("%s %d %.1lf %.1lf %c", tmp.name, tmp.grade, tmp.reput, tmp.distance, tmp.meal);
}