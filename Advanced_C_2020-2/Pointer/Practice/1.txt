#pragma warning (disable:4996)
#include <stdio.h>

int main(){
	int x, y, z;
	int* px = &x, * py = &y, * pz = &z, * tmp = NULL;	// swap에 필요한 tmp 선언

	scanf("%d %d %d", px, py, pz);

	// pointer swap
	tmp = pz;
	pz = py; 
	py = px;
	px = tmp;

	printf("%d %d %d", *px, *py, *pz);

	return 0;
}