#include<stdio.h>
#define MAXSIZE 101
#define INF 1<<21
#pragma warning(disable : 4996)
G[MAXSIZE][MAXSIZE];
color[MAXSIZE];//边集合列表
d[MAXSIZE];
p[MAXSIZE];//用于记录顶点V的父节点

enum col{
	WHITE = 0, GRAY,BLACK
};
void prim(int n ) {
	int u;
	for (int i = 1; i <= n; i++) {
		color[i] = WHITE;
		d[i] = INF;
	}
	d[1] = 0;
	p[1] = -1;

	while (1) {
		int mincost = INF;
		for (int i = 1; i <= n; i++) {
			if (color[i] != BLACK && d[i] < mincost)//找出最小边 
			{
				mincost = d[i];
				u = i;//最小顶点
			}
		}
		if (mincost == INF)break;//出口

		color[u] = BLACK;

		for (int i = 1; i <= n; i++) {
			if (color[i] != BLACK && G[u][i] != -1) {
				if (G[u][i]<d[i])
				{
					color[i] = GRAY;
					d[i] = G[u][i];
					p[i] = u;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] == BLACK) sum += d[i];
	}
	printf("%d\n", sum);
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	prim(n);
	return 0;
}