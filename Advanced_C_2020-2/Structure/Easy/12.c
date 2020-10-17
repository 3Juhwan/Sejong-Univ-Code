#pragma warning (disable:4996)
#include <stdio.h>

struct student {
	char name[10];
	int score[3];
	double avg;
};

void read_data(struct student x[]);
void cal_avg(struct student x[]);
void sort(struct student x[]);
void print_score(struct student x[]);

int main() {
	struct student data[10] = { 0 }, * p = NULL;

	read_data(data);
	cal_avg(data);
	sort(data);
	print_score(data);

	return 0;
}

void read_data(struct student x[]) {
	for (int i = 0; i < 10; i++)
		scanf("%s %d %d %d", x[i].name, &x[i].score[0], &x[i].score[1], &x[i].score[2]);
}

void cal_avg(struct student x[]) {
	for (int i = 0;i < 10;i++)
		x[i].avg = (x[i].score[0] + x[i].score[1] + x[i].score[2]) / 3.0;
}

void sort(struct student x[]) {
	struct student tmp = { 0 };
	for (int i = 0;i < 9; i++)
		for (int j = i + 1; j < 10; j++)
			if (x[i].avg < x[j].avg)
			{
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
}

void print_score(struct student x[]) {
	printf("%s %.2lf\n", x[0].name, x[0].avg);
	printf("%s %.2lf\n", x[9].name, x[9].avg);
	printf("%s %.2lf\n", x[7].name, x[7].avg);
	printf("%s %.2lf\n", x[8].name, x[8].avg);
	printf("%s %.2lf\n", x[9].name, x[9].avg);
}