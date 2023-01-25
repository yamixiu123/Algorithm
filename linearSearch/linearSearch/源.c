#include<stdio.h>
#pragma warning(disable : 4996)

int A[10000];
int main() {
	int a, b,key,count =0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) scanf("%d", &A[i]);
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &key);
		for (int j = 0; j < a; j++) {
			if (A[j] == key) {
				count++;
			};
		}
	} 
	printf("%d\n", count);

	return 0;
}