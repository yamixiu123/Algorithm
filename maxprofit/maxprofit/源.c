#include<stdio.h>
# define SIZE 200000


int main() {
	int N;
	int A[SIZE];
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) scanf_s("%d", &A[i]);
	
	int maxv = A[1] - A[0];
	int minv = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] - minv > maxv)maxv = A[i] - minv;
		if (A[i] < minv) minv = A[i];
	}
	printf("%d\n", maxv);
	
	
	return 0;
}