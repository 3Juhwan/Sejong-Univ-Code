#include<stdio.h>

int main(){
	int n1 = 0, n2 = 0;
	double sum;
	scanf("%d %d", &n1, &n2);
	sum = n1 * 0.4 + n2 * 0.6;

	if (sum >= 85.5)
		printf("A ");
	else if (sum < 85.5 && sum >= 75.5)
		printf("B ");
	else if (sum < 75.5 && sum >= 60.0)
		printf("C ");
	else
		printf("F ");

	if (sum >= 60 || n2 >= 90)
		printf("PASS");
	else
		printf("FAIL");
	return 0;
}