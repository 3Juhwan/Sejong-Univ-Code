#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char arr[101] = "", str[101]="";
	int len1 = 0, len2 = 0, cnt = 0, flag = 0;

	gets_s(arr, 101);
	gets_s(str, 101);
	
	len1 = strlen(arr);
	len2 = strlen(str);

	for(int i = 0; i <= len1 - len2 ; i++)
	{
		for (int j = 0; j < len2;j++)
		{
			if (arr[i + j] == str[j])
				cnt++;
		}
		if (cnt == len2)
			flag++;
		cnt = 0;
	}

	printf("%d", flag);

	return 0;
}