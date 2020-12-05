#include<stdio.h>

int isLeapYear(int year);
int getTotalNumberOfLeapYear(int startYear, int endYear);

int main(void) {
	int startYear = 0, endYear = 0;
	scanf("%d%d", &startYear, &endYear);
	printf("%d", getTotalNumberOfLeapYear(startYear, endYear));
	return 0;
}

int isLeapYear(int year){
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return 1;
			return 0;
		}
		else
			return 1;
	}
	return 0;
}

int getTotalNumberOfLeapYear(int startYear, int endYear) {
	int cnt = 0;
	for (int i = startYear; i <= endYear; i++) 
		cnt += isLeapYear(i);

	return cnt;
}