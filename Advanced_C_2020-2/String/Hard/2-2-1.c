#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[1010] = "";
	char* p = arr, * q = arr, *tmp = NULL;
	char** word = NULL;
	int size = 1, len = 0, w_len = 0, i = 0;

	gets_s(arr, 1010);
	len = strlen(arr);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			size++;
		}
		p++;
	}

	word = (char**)malloc(size * sizeof(char*));
	if (word == NULL) {
		printf("Insufficient Memory");
		return -1;
	}

	p = arr;
	while (p < arr + len)
	{
		w_len = strlen(p);
		word[i] = (char*)malloc((w_len + 1) * sizeof(char));
		if (word[i] == NULL) {
			printf("Insufficient Memory");
			return -1;
		}

		strcpy(word[i], p);

		i++;
		p += w_len + 1;
	}

	for (int i = 0;i < size; i++)
		printf("%s\n", word[i]);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*word[j] > * word[j + 1])
			{
				tmp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = tmp;
			}
		}
	}

	for (int i = 0;i < size; i++)
		printf("%s\n", word[i]);

	for (int i = 0; i < size; i++)
		free(word[i]);

	free(word);

	return 0;
}