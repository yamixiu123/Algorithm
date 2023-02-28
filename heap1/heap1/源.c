#include<stdio.h>
#pragma warning(disable : 4996)
A[250] = { -1 };

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= n; i++) {
		printf("node %d: key = %d, ", i , A[i]);
		if (i != 1)printf("parent key = %d, ", A[i / 2]);
		if (i*2 + 1 <= n) printf("left key = %d, right key = %d, ",A[i * 2],A[i * 2 + 1]);
		else if (i * 2 <= n)printf("left key = %d, ", A[i * 2]);
		printf("\n");
	}
	return 0;
}