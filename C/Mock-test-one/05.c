#include<stdio.h>

int main(){
	int N = 0, swap = 0, num = 0;
	scanf("%d", &N);
	swap = N;
	while (swap > 0) {
		num = num * 10 + swap % 10;
		swap /= 10;
		N *= 10;
	}
	N += num;

	printf("%d\n%d", N, N%131);

	return 0;
}