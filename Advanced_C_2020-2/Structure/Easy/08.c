#pragma warning (disable:4996)
#include <stdio.h>

struct complex {
	double real;
	double img;
};

struct complex add(struct complex x, struct complex y);

int main() {
	struct complex x = { 0, }, y = { 0, }, z = { 0, };
	
	scanf("%lf %lf", &x.real, &x.img);
	scanf("%lf %lf", &y.real, &y.img);

	z = add(x, y);

	printf("%.1lf + %.1lfi", z.real, z.img);

	return 0;
}

struct complex add(struct complex x, struct complex y) {
	struct complex z = { 0, };
	z.real = x.real + y.real;
	z.img = x.img + y.img;
	return z;
}