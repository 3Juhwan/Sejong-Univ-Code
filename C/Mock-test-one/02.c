#include<stdio.h>

int main(){
	int N = 0, price = 0, p1 = 0, p2 = 0;
	scanf("%d", &N);
	while (N > 0) {
		scanf("%d %d %d", &price, &p1, &p2);

		if (price - p1 < 0 && price - p2 < 0) printf("draw\n");
		else if (price - p1 < 0 || price - p2 < 0)
			if (p1 < p2)printf("A\n");
			else printf("B\n");
		else
			if (p1 == p2)printf("draw\n");
			else if (p1 > p2) printf("A\n");
			else printf("B\n");

		N--;
	}

	return 0;
}