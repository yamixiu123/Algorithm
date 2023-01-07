#include<stdio.h>
#include<stdbool.h>

bool  isPrime(int i) {
	int j;
	bool flag = false;
	for (j = 2; j*j <= i; j++) {
		if (i % j == 0) break;
	}
	if (j*j > i) flag = true;

	return flag;
}

int main() {
	int N,j;
	int p=0;
	int A[10000];

	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		j = A[i];
		if (isPrime(j))
			p++;
	}
	printf("%d\n", p);
	return 0;
}