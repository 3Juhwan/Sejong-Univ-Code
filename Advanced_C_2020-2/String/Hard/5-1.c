#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cut_word(char arr[], char* word[]);
void sorting(char* word[], int len);

int main() {
	char str[1001] = "", * word[100] = { NULL };
	int K = 0, len = 0;

	gets_s(str, 1001);

	len = cut_word(str, word);

	sorting(word, len);
	
	scanf("%d", &K);

	printf("%s", word[K - 1]);

	return 0;
}

int cut_word(char arr[], char* word[]) {
	char* p = arr, * q = arr;
	int size = 0;

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			word[size] = q;
			size++;
			q += strlen(q) + 1;
		}
		p++;
	}
	word[size] = q;
	size++;

	return size;
}

void sorting(char* word[], int len) {
	char* tmp = NULL;
	int len1 = 0, len2 = 0;

	for (int i = 0; i < len - 1;i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			len1 = strlen(word[j]);
			len2 = strlen(word[j + 1]);

			if (len1 < len2)
			{
				tmp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = tmp;
			}
			else if (len1 == len2 && strcmp(word[j], word[j + 1]) > 0)
			{
				tmp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = tmp;
			}
		}
	}
}