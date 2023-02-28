#include<stdio.h>
#pragma warning(disable : 4996)

int A[500001]={ -1 };

void maxHeapify(int i,int n) {
	int l = i * 2;
	int r = i * 2 + 1;
	int largest=i;
	if (l <= n && A[l] > A[largest]) {
		largest = l;
	}
	if (r <= n && A[r] > A[largest]) {
		largest = r;
	}

	if (largest != i) {
		int temp;
		temp = A[largest];
		A[largest] = A[i];
		A[i] = temp;
		maxHeapify(largest, n);
	}

};

void buildMaxHeap(int n){
	for (int i = n / 2; i >= 1; i--) {
		maxHeapify(i,n);
	}

}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	buildMaxHeap(n);
	for (int i = 1; i <= n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
	return 0;
}