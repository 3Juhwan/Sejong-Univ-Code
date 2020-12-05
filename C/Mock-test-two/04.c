#include<stdio.h>

int main() {
	char x[200], y[200];
	int  i = 0, j = 0;
	int cntx = 0, cnty = 0, tmp = 0, cnt_same = 0;

	scanf("%c", &x[0]);
	for (i = 1; x[i - 1] != '*';i++) {
		scanf("%c", &x[i]);				//cntx 범위
		cntx++;
	}
	scanf("%c", &y[0]);
	for (i = 1; y[i - 1] != '*';i++) {
		scanf("%c", &y[i]);
		cnty++;
	}

	for (i = 0; cntx != i && cnty != i && tmp == 0;i++) {
		if (x[i] < y[i]) {
			for (j = 0; j < cntx;j++)
				printf("%c", x[j]);
			tmp++;
			break;
		}
		else if (x[i] > y[i]) {
			for (j = 0; j < cnty;j++)
				printf("%c", y[j]);
			tmp++;
			break;
		}
	}

	for (i = 0; cntx != i && cnty != i;i++) {
		if (x[i] == y[i])
			cnt_same++;
	
	
	
	}
	if (cnt_same == i) {
		if (cntx < cnty)
			for (j = 0; j < cntx;j++)
				printf("%c", x[j]);
		else
			for (j = 0; j < cnty;j++)
				printf("%c", y[j]);

	}

	return 0;
}