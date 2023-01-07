#include<stdio.h>
#define SIZE 100

void selectionSort(int A[], int N) {
	int minj;
	int count = 0;
	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[minj] > A[j]) minj = j;
		}
		if (minj != i) {
			int temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			count++;
		}

	}
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1) printf("%d ",A[i]);
		else printf("%d\n%d\n",A[i],count);
	}
}


int main() {
	int N;
	int A[SIZE];
	
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}

	selectionSort(A,N);

	return 0;
}