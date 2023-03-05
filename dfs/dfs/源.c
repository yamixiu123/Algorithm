#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 1001
#pragma warning(disable : 4996)

int G[MAXSIZE][MAXSIZE] = {0};

int vis[MAXSIZE][MAXSIZE];//标记数组

int S[MAXSIZE] = { 0 };//stack

int []
//stack status
int index = 0;
int count = 0;

//使用递归
void dfs(int SX,int SY,int FX, int FY) {
	d[i] = 0;
	while (count != 0) {
		int tmp = dequeue();
		depth = d[tmp];
		for (int k = 1; k <= n; k++) {//遍历邻接点
			if (G[tmp][k] == 1 && d[k] == -1) {
				d[k] = depth + 1;//入队前先标记！
				enqueue(k);
			}	//邻接点入队
		}
	}
}


int main() {
	int N, M, T;
	int SX, SY, FX, FY;
	scanf("%d %d %d", &N,&M,&T);
	scanf("%d %d", &SX,&SY,&FX,&FY);
	//初始化数组
	for (int i = MAXSIZE - 1 - N; i <= MAXSIZE - 1; i++){
		for (in j = MAXSIZE - 1 - M; i <= MAXSIZE - 1; j++) {
			G[i][j] = -1;
		}
	}
	//障碍物标记为-1
	for (int i = 1; i <= T; i++) {
		int T_x,T_y;
		scanf("%d %d", &T_x, &T_y);
		G[T_x][T_y] = -1;
	}
	//如何对比方案是否一样:通过的点排列称为长数字 然后对其进行对比
	bfs(SX,SY,FX,FY);

}
