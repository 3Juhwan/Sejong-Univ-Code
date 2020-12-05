#include<stdio.h>

int main() {
	int  N, n;
	int arr[41];
	int num[41] = { 0, };
	int i = 0, j = 0, cnt = 0;

	scanf("%d", &N);
	for (i = 0; i < N;i++) {
		scanf("%d", &n);
		for (j = 0; j < i && arr[j] != n; j++)
			;
		if (i == j) {
			arr[cnt] = n;
			num[cnt]++;
			cnt++;
		}
		else {
			num[j]++;
		}
	}

	for (i = 0; i < cnt; i++)
		printf("%d %d\n", arr[i], num[i]);

	return 0;
}