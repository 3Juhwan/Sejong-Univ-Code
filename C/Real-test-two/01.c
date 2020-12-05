#include<stdio.h>

int main(){

	int n = 0, arr[110], subject = 0, subject_num = 0;
	int i = 0, j = 0;

	scanf("%d", &n);
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	
	for (i = 0; i < n - 1;i++) {
		int tmp = arr[n - 1] - arr[i];

		if (tmp < 0)
			tmp = tmp * (-1);
		
		if (subject < tmp){
			subject = tmp;
			subject_num = arr[i];
		}
		else if (subject == tmp) {
			if (arr[i] > subject_num) {
				subject = tmp;
				subject_num = arr[i];
			}
		}

	}

	printf("%d", subject_num);

	return 0;
}