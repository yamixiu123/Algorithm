#include<stdio.h>
#define N 101
#define INT_MAX 1000000
#pragma warning(disable : 4996)
int p[N];
int M[N][N];



void matrixChainOrder(int p[], int n) {
	for (int i = 1; i <= n; i++)//n 矩阵链总长度
		M[i][i] = 0; // 初始化矩阵乘法中单个矩阵的代价为0
	for (int L = 2; L <=n; L++) { // L表示矩阵链的长度，从2开始，因为长度为1时无需计算
		for (int i = 1; i <= n - L + 1; i++) {//开始 下标
			int j = i + L - 1;
			M[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				if (M[i][j] > M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j]) {
					M[i][j] = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
				}
			}
		}
	}
}


int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		scanf("%d %d", &p[i-1],&p[i]);
	}if (n != 2) {
		matrixChainOrder(p, n);
		printf("%d\n", M[1][n]);
	}
	else
	{
		printf("%d\n", p[0] * p[1] * p[2]);
	}

	return 0;
}