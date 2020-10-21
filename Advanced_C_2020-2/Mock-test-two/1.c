#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

double atof2(char ch[], int N, int M);

int main() {
	char arr[1001] = "";
	char* p = arr;
	int N = 0, M = 0;
	double result = 0.0;

	scanf("%c", p);
	while (*p != '*')
	{
		p++;
		scanf("%c", p);
	}
	scanf("%d %d", &N, &M);

	result = atof2(arr, N, M);

	printf("%lf", result);

	return 0;
}

double atof2(char ch[], int N, int M) {
	char* p = ch;
	double result = 0.0;
	int n1 = 0, n2 = 0, digit = 1, lest = 0;

	while (*p != '.')
	{
		n1 = n1 * 10 + *p - '0';
		p++;
	}
	p++;
	n1 *= N;

	while (*p != '*')
	{
		n2 = n2 * 10 + *p - '0';
		digit *= 10;
		p++;
	}
	n2 = (n2 * M) % digit;

	result = n1 + (double)n2 / digit;

	return result;
}