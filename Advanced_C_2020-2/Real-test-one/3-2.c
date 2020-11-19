#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char A[151] = "", B[11] = "", C[11] = "", output[301]="";
	char* p = A, * q = A;

	gets_s(A, 151);
	gets_s(B, 11);
	gets_s(C, 11);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			if (strcmp(q, B) == 0)
			{
				strcat(output, C);
				strcat(output, " ");
			}
			else
			{
				strcat(output, q);
				strcat(output, " ");
			}
			q += strlen(q) + 1;
		}
		p++;
	}
	if (strcmp(q, B) == 0)
	{
		strcat(output, C);
		strcat(output, " ");
	}
	else
	{
		strcat(output, q);
		strcat(output, " ");
	}

	printf("%s", output);

	return 0;
}