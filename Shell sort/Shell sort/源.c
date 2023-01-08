#include <stdio.h>
#define SIZE 1000000
#pragma warning(disable : 4996)

int A[SIZE];

void insertionSort(int n, int m, int* cnt) {
	int i, v, k;
	for (i = 0; i < n; i++)//遍历数组
	{
		k = i - m; //减去步长后下标
		v = A[i];	//存储最右变量
		for (; k >= 0&&A[k]>v; k -= m) { //减去步长下标没越界
				A[k + m] = A[k];//交换步长下标元素;
				(*cnt)++;
		}
		A[k + m] = v;
	}
}

void shellSort(int n,int* cnt){
	int G[100];
	int m = 0;
	int size = n;
	while (size / 2 > 1) {
		size /= 2;
		G[m] = size;
		m++;
	}
	G[m] = 1;
	printf("%d\n", m + 1);

	for (int j = 0; j < m + 1; j++) {
		if (j != m) {
			printf("%d ", G[j]);
		}
		else printf("%d\n", G[j]);
	}
		
	for (int i = 0; i <m+1; i++) {
		insertionSort(n,G[i],cnt);//size of array,foot length,cnt
	}
}


int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	shellSort(n,&cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) printf("%d\n",A[i]);
	return 0;
}