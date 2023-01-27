#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

int A[2000000];
int B[2000000];
int tmpA[10000] = { 0 };
int n;
countingSort(){

	for (int i = 0; i < n; i++) {
		tmpA[A[i]]++;
	}
	for (int i = 1; i < 10001; i++) {
		tmpA[i] += tmpA[i - 1];
	}
	for (int i = n - 1; i > -1; i--) {
		B[tmpA[A[i]]-1] = A[i];	
		tmpA[A[i]]--;
	}
	for (int i = 0; i < n-1; i++) {
		printf("%d ", B[i]);
	}
	printf("%d\n", B[n-1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &A[i]);
	countingSort();
	return 0;
}