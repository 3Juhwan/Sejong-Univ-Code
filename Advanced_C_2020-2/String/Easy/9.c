#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char ch[]);

int main() {
	char arr[31] = "";
	int size = 0, N = 0;

	scanf("%s", arr);

	size = strlen(arr);

	N = check(arr);

	printf("%d %d", size, N);

	return 0;
}

int check(char ch[]) {
	int len = 0;

	len = strlen(ch);

	for (int i = 0; i < len / 2;i++)
		if (ch[i] != ch[len - i - 1])
			return 0;
	return 1;
}