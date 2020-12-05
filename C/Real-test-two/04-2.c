#include<stdio.h>

int main() {
	int n = 0, arr[110], is = 0, cnt = 1, max = 1,max_index = 0;
	int i = 0, j = 0, max_num[110], k = 0;
	scanf("%d", &n);
	for (i = 0; i < n;i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n -1;i++) {
		if (arr[i] * arr[i + 1] < 0)
			cnt++;
		else {
			if (max <= cnt) {
				max = cnt;
				for (k = 0, j = i - cnt + 1; j < i + 1;j++,k++) {
					max_num[k] = arr[j];
				}
				max_index = cnt;
			
			}
			cnt = 1;
		}
	}
	if (max <= cnt) {
		max = cnt;
		for (k = 0, j = i - cnt + 1; j < i + 1;j++, k++) {
			max_num[k] = arr[j];
		}
		max_index = cnt;

	}

	printf("%d\n", max);
	for (i = 0; i < max_index;i++)
		printf(" %d", max_num[i]);


	return 0;
}