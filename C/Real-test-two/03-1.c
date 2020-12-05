#include<stdio.h>

int main(){
	int n, arr[30], cnt1 = 1, cnt2 = 0;
	int i = 0, j = 0;

	scanf("%d", &n);
	for(i = 0; i< n;i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n;i++) {
		for (j = i; j < n; j++) {
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		printf(" %d", arr[i]);
	}
	printf("\n");
	printf(" 1");
	for (i = 1;i < n;i++,cnt1++) {
		if (arr[i] == arr[i - 1]) {
			cnt2++;
			printf(" %d", cnt1 - cnt2 + 1);
		}
		else {
			printf(" %d", i + 1);
			cnt2 = 0;
		}
	}

	return 0;
}