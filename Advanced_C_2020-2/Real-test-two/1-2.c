#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_info {
	char name[11];
	int S1;
	int S2;
	double avg;
}student_info;

void insertData(student_info* s, int N);
double getAllavg(student_info s[], int N);
void printResult(student_info* s, int N, double avg);

int main() {
	int N = 0;
	double total_avg = 0.0;
	student_info S[100] = { "" };

	scanf("%d", &N);
	getchar();

	insertData(S, N);

	total_avg = getAllavg(S, N);

	printResult(S, N, total_avg);

	return 0;
}

void insertData(student_info* s, int N) {
	student_info* p = s;

	for(p = s; p < s+ N;p++)
	{
		scanf("%s %d %d", p->name, &p->S1, &p->S2);
		p->avg = p->S1 * 0.4 + p->S2 * 0.6;
	}
}

double getAllavg(student_info s[], int N) {
	student_info* p = s;
	int bottom_st = 0;
	double total_avg = 0.0;

	for (p = s; p < s + N;p++)
		total_avg += p->avg;

	total_avg /= (double)N;

	for (p = s;p < s + N;p++)
		if (total_avg >= p->avg)
			bottom_st++;

	printf("%.2lf %d\n", total_avg, bottom_st);

	return total_avg;
}

void printResult(student_info* s, int N, double avg) {
	student_info* p = s;

	for (p = s; p < s + N; p++)
	{
		if (p->avg <= avg)
			printf("%s %.2lf\n", p->name, p->avg);
	}
}