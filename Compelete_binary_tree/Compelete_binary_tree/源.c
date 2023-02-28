#include<stdio.h>
A[250] = { -1 };

int main() {
	int n;
	scanf("d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) {
		printf("node %d: key = %d, ", i + 1, A[i]);
		if (i != 0)printf("parent key = %d, "A[i / 2]);
		else if (i * 2 + 1 < n)printf("left key = %d, right key = %d, ", A[i * 2], A[i * 2 + 1]);
		else if (i * 2 < n)printf("left key = %d, ", A[i * 2]);
		printf("\n");
	}
	return 0;
}