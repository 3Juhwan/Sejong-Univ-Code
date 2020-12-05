#include<stdio.h>

int main(){
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	char str;

	scanf("%c", &str);

	while (str != '*') {

		if (str >= 'A' && str <= 'Z')
			cnt1++;
		else if (str >= 'a' && str <= 'z')
			cnt2++;
		else if (str >= '0' && str <= '9')
			cnt3 += str - '0';
		else
			cnt4++;
		scanf("%c", &str);
	}
	printf("%d %d %d %d", cnt1, cnt2, cnt3, cnt4);

	return 0;
}