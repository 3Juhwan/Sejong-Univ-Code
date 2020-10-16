#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char *strnum[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char* strdigit[4] = {"", "TEN", "HUN", "THO" };
	int input = 0, output = 0;
	int digit = 1000;
	int tmp = 3;

	scanf("%d", &input);

	while (digit > 0)
	{
		output = input / digit;
		if (output)
			printf("%s %s ", strnum[output - 1], strdigit[tmp]);

		tmp--;
		input %= digit;
		digit /= 10;
	}

	return 0;
}