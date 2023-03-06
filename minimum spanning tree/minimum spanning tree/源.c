#include<stdio.h>
#define MAXSIZE 101
#define INF 1<<21
#pragma warning(disable : 4996)
G[MAXSIZE][MAXSIZE];
color[MAXSIZE];//�߼����б�
d[MAXSIZE];
p[MAXSIZE];//���ڼ�¼����V�ĸ��ڵ�

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
			if (color[i] != BLACK && d[i] < mincost)//�ҳ���С�� 
			{
				mincost = d[i];
				u = i;//��С����
			}
		}
		if (mincost == INF)break;//����

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