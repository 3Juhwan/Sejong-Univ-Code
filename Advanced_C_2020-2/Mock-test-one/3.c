#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main() {
	char str[16] = "";
	char smb1 = '+', smb2 = '*';
	int len = 0, cvt1 = 0, cvt2 = 0;

	scanf("%s", str);
	len = strlen(str);		// 1번

	for (int i = 0, j = 0; i < len - 1 + j; i++)
	{
		cvt1 = str[i];
		cvt2 = str[i + 1];
		if (cvt1 % 2 == 1 && cvt2 % 2 == 1)
		{
			StringAdd(str, smb1, i);
			i++;
			j++;
		}
		else if (cvt1 % 2 == 0 && cvt2 % 2 == 0)
		{
			StringAdd(str, smb2, i);
			i++;
			j++;
		}
	}

	printf("%s", str);

	return 0;
}

void StringAdd(char arr[], char ch, int index) {
	int i = 0, len = strlen(arr);		// 2번

	for (i = len; i > index; i--)
		arr[i + 1] = arr[i];

	arr[i + 1] = ch;
}

int Convertor(char x) {
	return x - '0';
}