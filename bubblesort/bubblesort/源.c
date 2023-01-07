#include<stdio.h>
#include<stdbool.h>
#define SIZE 100

int main() {
	int flag = true;
	int N,A[SIZE];
	int t = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) scanf_s("%d", &A[i]);

	while (flag) {
		flag = false;
		for (int i = 1; i < N; i++) {
			int temp;
			if (A[i] < A[i - 1]) {
				temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				flag = true;
				t++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d", A[i]);
		if (i != N - 1)printf(" ");
	}
	printf("\n%d\n",t);
}