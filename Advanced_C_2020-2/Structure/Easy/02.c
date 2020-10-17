#pragma warning (disable:4996)
#include <stdio.h>

struct Time {
	int hour;
	int minute;
	int second;
};

int main() {
	struct Time T1 = { 0, }, T2 = { 0, }, T3 = { 0, };
	int time1 = 0, time2 = 0, dif = 0;

	scanf("%d %d %d", &T1.hour, &T1.minute, &T1.second);
	scanf("%d %d %d", &T2.hour, &T2.minute, &T2.second);

	time1 = T1.hour * 3600 + T1.minute * 60 + T1.second;
	time2 = T2.hour * 3600 + T2.minute * 60 + T2.second;

	dif = time2 - time1;

	T3.hour = dif / 3600;
	T3.minute = dif % 3600 / 60;
	T3.second = dif % 60;

	printf("%d %d %d", T3.hour, T3.minute, T3.second);

	return 0;
}