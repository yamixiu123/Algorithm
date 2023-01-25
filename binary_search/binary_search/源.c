#include<stdio.h>
#include<stdbool.h>;
#pragma warning(disable : 4996)

#define N 100000
#define Q 5000
int A[N], B[Q];
int count = 0;
int binary_search(int n, int b,int key) {

	int left = b;
	int right = n;

	while (right >= left) {
		int mid = (right + left) / 2;
		if (A[mid] == key) {
			count++;
		}
		else if (A[mid] > key) {
			binary_search(mid - 1, left, key);
		}
		else {
			binary_search(right, mid + 1, key);
		}
		return 0;
	}	
};

int main() {
	int n, q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &A[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &B[i]);
		binary_search(n, 0,B[i]);
	}
	printf("%d\n", count);

	return 0;
}