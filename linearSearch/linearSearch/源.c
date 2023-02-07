#include<stdio.h>
#pragma warning(disable : 4996)

int A[10000] = {-1};
int main() {
	int a, b, key;
	int count = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &key);
		for (int i = 0; i < a; i++) {
			if (A[i] == key) {
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}