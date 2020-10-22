#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char arr1[31] = "", arr2[31] = "";
	char* p = arr1, * q = arr2;
	int num[30] = { 0, };
	int size = 0, len1 = 0, len2 = 0, total = 0;

	scanf("%s", arr1);
	scanf("%s", arr2);

	/*gets_s(arr1, 31);
	gets_s(arr2, 31);*/

	len1 = strlen(arr1);
	len2 = strlen(arr2);

	while (p < arr1 + len1 || q < arr2 + len2)
	{
		if (*p == *q)
			num[size] = 1;
		else if ((*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z') && (*q >= 'a' && *q <= 'z' || *q >= 'A' && *q <= 'Z'))
			num[size] = *p - *q;
		else if ((*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z') && (*q >= '0' && *q <= '9') || (*q >= 'a' && *q <= 'z' || *q >= 'A' && *q <= 'Z') && (*p >= '0' && *p <= '9'))
			num[size] = -50;
		else if (*p == '\0' || *q == '\0')
			num[size] = -200;
		else
			num[size] = -100;
		p++;
		q++;
		size++;
	}

	for (int i = 0; i < size; i++)
		total += num[i];

	printf("%d (", total);
		printf("%d ", num[i]);
	   
	return 0;
}