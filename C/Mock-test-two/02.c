#include<stdio.h>

int main() {
	int N = 0, arr[3] = { 0, };
	int sum = 0;
	int i = 0, j = 0, k = 0;
	scanf("%d", &N);

	for (i = 1; ;i++) {
		for (j = 2; ;j += 2) {
			for (k = 1; k < i || k < j;k++) {
				sum = i * 900 + j * 750 + k * 200;
				if (sum == N)
					printf("%d %d %d\n", i, j, k);
			}
			if (i * 900 + j * 750 > N)
				break;
		}
		if (i * 900 > N)
			break;
	}

	return 0;
}