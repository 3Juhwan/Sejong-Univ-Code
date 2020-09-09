#pragma warning (disable:4996)
#include <stdio.h>

void strcopy(char a[], char b[]);

int main() {
	char a[6], b[6];
	char* p = NULL;

	for (p = b; p < b + 6; p++)
		scanf("%c", p);

	strcopy(a, b);

	for (p = a; p < a + 6; p++)
		printf("%c", *p);

	return;
}

void strcopy(char a[], char b[]) {
	for (int i = 0;i < 6;i++)
		*(a + i) = *(b + i);
}