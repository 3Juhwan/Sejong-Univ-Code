#include<stdio.h>

int main() {
	int n = 0, arr[110], is = 0, cnt = 1, max = 0;
	int i = 0, j = 0;
	scanf("%d", &n);
	for (i = 0; i < n;i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n -1;i++) {
		if (arr[i] * arr[i + 1] < 0)
			cnt++;
		else {
			if (max < cnt) 
				max = cnt;
				cnt = 1;
		}
	}
	if (max < cnt)
		max = cnt;

	printf("%d", max);



	return 0;
}
