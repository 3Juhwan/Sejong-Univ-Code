#pragma warning (disable:4996)
#include <stdio.h>

typedef struct{
	int id;
	int arrival_time;
	int service_time;
	int waiting_time;
}_bank;

void waitingtime(_bank guest[], int N);
double avgtime(_bank guest[], int N);

int main() {
	_bank Customer[100] = { 0, };
	int N = 0;
	double avg = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &Customer[i].id, &Customer[i].arrival_time, &Customer[i].service_time);

	waitingtime(Customer, N);

	avg = avgtime(Customer, N) / N;

	printf("%.2lf", avg);

	return 0;
}

void waitingtime(_bank guest[], int N) {
	int total = 0;

	for (int i = 0; i < N; i++)
	{
		total = 0;
		for (int j = 0; j < i;j++)
			total += guest[j].service_time;

		guest[i].waiting_time = total - guest[i].arrival_time;
	}
}

double avgtime(_bank guest[], int N) {
	double avg = 0.0;

	for (int i = 0; i < N; i++)
		avg += guest[i].waiting_time;
	return avg;
}