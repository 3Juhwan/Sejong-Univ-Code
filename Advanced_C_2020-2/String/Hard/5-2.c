#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cut_word(char arr[], char* word[]);
void sorting(char* word[], int len);
void similar(char* standard, char* compare);

int main() {
	char str[1001] = "", * word[100] = { NULL }, * stdstr = NULL;
	int K = 0, len = 0;

	gets(str);

	len = cut_word(str, word);

	sorting(word, len);

	scanf("%d", &K);

	stdstr = word[K - 1];

	printf("%s\n", stdstr);

	for (int i = 0; i < len;i++)
		if (word[i] != stdstr)
			similar(stdstr, word[i]);

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

void similar(char* standard, char* compare) {

	char copyStandard[101];
	char copyCompare[101];

	strcpy(copyStandard, standard);
	strcpy(copyCompare, compare);

	for (char* p = copyStandard; *p != '\0'; p++)
	{
		for (char* q = copyCompare; *q != '\0'; q++)
		{
			if (*p == *q)
			{
				char tmp[101];
				strcpy(tmp, p + 1);
				strcpy(p, tmp);

				strcpy(tmp, q + 1);
				strcpy(q, tmp);

				p--;
				q--;
			}

		}
	}

	if (strlen(copyStandard) <= 1 && strlen(copyCompare) <= 1)
	{
		printf("%s\n", compare);
	}


}