#include <stdio.h>

void insertionSort(int arr[], int size) {
	int tmp;
	for (int i = 0; i < size; i++) {
		tmp = arr[i];
		int j = i;
		for (; j - 1 >= 0 && arr[j - 1] > tmp; j--) {
				arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
		for (int k=0; k < size; k++) {
			printf("%d", arr[k]);
			if (k != size - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	int N, i;
	scanf_s("%d", &N);
	int A[100];
	for (i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	insertionSort(A, N);
	return 0;
}
