#pragma warning (disable:4996)
#include <stdio.h>

void strcopy(char a[], char b[]);

int main() {
	char arr1[6] = { '\0' }, arr2[6] = { '\0' };
	char* p = NULL;

	for (p = arr2; p < arr2 + 6; p++)
		scanf("%c", p);

	strcopy(arr1, arr2);

	for (p = arr1; p < arr1 + 6; p++)
		printf("%c", *p);

	return 0;
}

void strcopy(char a[], char b[]) {
	for (char* p = b, *q = a; p < b + 6;p++, q++)
		*q = *p;
}