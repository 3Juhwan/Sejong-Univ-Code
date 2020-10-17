#pragma warning (disable:4996)
#include <stdio.h>

struct Vector {
	int x;
	int y;
	int z;
};

int main() {
	struct Vector V1 = { 0, }, V2 = { 0, }, V3 = { 0, };

	scanf("%d %d %d", &V1.x, &V1.y, &V1.z);
	scanf("%d %d %d", &V2.x, &V2.y, &V2.z);

	V3.x = V1.x * V2.x;
	V3.y = V1.y * V2.y;
	V3.z = V1.z * V2.z;

	printf("%d %d %d\n%d", V3.x, V3.y, V3.z, V3.x + V3.y + V3.z);

	return 0;
}