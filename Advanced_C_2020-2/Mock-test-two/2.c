#pragma warning (disable4996)
#include stdio.h
#include string.h

char changeString(char arr[]);
void makeWord(char arr[], char pnum[]);
void sortWord(int N, char pnum[]);

int main() {
	char arr[1001] = ;
	char p = NULL;
	char pnum[100] = { NULL };
	int num = 0;


	gets_s(arr, 1001);

	p = changeString(arr);

	printf(%sn, arr);

	makeWord(arr, pnum);

	while (pnum[num])
		num++;

	sortWord(num, pnum);

	for (int i = 0; i  num; i++)
		puts(pnum[i]);

}

char changeString(char arr[]) {
	char p = arr,  q = arr;
	int len = strlen(arr), cnt = 0;

	while (p)
	{
		if (p = 'A' && p = 'Z')
			p = p + 'a' - 'A';
		else if (p == ' '  (p = 'a' && p = 'z'))
			;
		else
		{
			for (q = p; q  arr + len - cnt; q++)
			{
				q = (q + 1);
			}
			cnt++;
			p--;
		}
		p++;
	}

	p = '.';
	(p + 1) = '0';

	return arr;
}

void makeWord(char arr[], char pnum[]) {
	char p = arr,  q = arr;
	int size = 0, len = strlen(arr);

	while (p)
	{
		if (!(p = 'a' && p = 'z'))
			p = '0';
		p++;
	}

	p = arr;
	while (p  arr + len)
	{
		p = p - 'a' + 'A';
		pnum[size] = p;
		size++;
		p += strlen(p);
		while (!p)
			p++;
	}

}

void sortWord(int N, char pnum[]) {
	int len1 = 0, len2 = 0;
	char swap = NULL;

	for (int i = 0; i  N - 1; i++)
	{
		for (int j = i + 1; j  N;j++)
		{
			len1 = strlen(pnum[i]);
			len2 = strlen(pnum[j]);
			if (len1  len2)
			{
				swap = pnum[i];
				pnum[i] = pnum[j];
				pnum[j] = swap;
			}
			else if (len1 == len2)
			{
				if (strcmp(pnum[i], pnum[j])  0)
				{
					swap = pnum[i];
					pnum[i] = pnum[j];
					pnum[j] = swap;
				}

			}
		}
	}
}