#include<stdio.h>
#pragma warning(disable : 4996)
A[100000];

int partion(int n) {
	int j = -1;
	int p = n - 1;
	for (int i = 0; i < p; i++) {
		if (A[i] <= A[p]) {
			int temp;
			j++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	int temp;
	temp = A[p];
	A[p] = A[j + 1];
	A[j + 1] = temp;
	return j + 1;
}

int main() {
	int n,pivot;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	pivot = partion(n);
	for (int i = 0; i < n; i++) {
		if (i == pivot) printf("[%d] ", A[pivot]);
		else if (i < n - 1) printf("%d ", A[i]);
		else printf("%d\n", A[i]);
	}
	
	return 0;
}