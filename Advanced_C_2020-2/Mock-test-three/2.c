#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex {
	double real;
	double imagine;
	double num;
}Complex;

Complex add(Complex x, Complex y);
Complex sub(Complex x, Complex y);
void abs_val(Complex* p1, Complex* p2, Complex* p3);

int main() {
	Complex N[3] = { 0 }, tmp = { 0 };

	for (int i = 0; i < 3; i++)
		scanf("%lf %lf", &N[i].real, &N[i].imagine);

	abs_val(&N[0], &N[1], &N[2]);

	tmp = add(N[0], N[2]);
	printf("%.1lf%+.1lfi\n", tmp.real, tmp.imagine);
	tmp = sub(N[0], N[2]);
	printf("%.1lf%+.1lfi\n", tmp.real, tmp.imagine);

	return 0;
}

Complex add(Complex x, Complex y) {
	Complex tmp = { 0 };
	tmp.real = x.real + y.real;
	tmp.imagine = x.imagine + y.imagine;
	return tmp;
}

Complex sub(Complex x, Complex y) {
	Complex tmp = { 0 };
	tmp.real = x.real - y.real;
	tmp.imagine = x.imagine - y.imagine;
	return tmp;
}

void abs_val(Complex* p1, Complex* p2, Complex* p3) {
	Complex tmp = { 0 };

	p1->num = sqrt(p1->real * p1->real + p1->imagine * p1->imagine);
	p2->num = sqrt(p2->real * p2->real + p2->imagine * p2->imagine);
	p3->num = sqrt(p3->real * p3->real + p3->imagine * p3->imagine);

	if (p1->num < p2->num) {
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
	if (p2->num < p3->num) {
		tmp = *p2;
		*p2 = *p3;
		*p3 = tmp;
	}
	if (p1->num < p2->num) {
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}