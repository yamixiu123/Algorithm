#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 1001
#pragma warning(disable : 4996)
int N, M, T;

int total = 0;

int map[MAXSIZE][MAXSIZE] = { 0 };
int vis[MAXSIZE][MAXSIZE];//标记数组
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };//方向数组

bool flag = false;
//使用递归
void  dfs(int SX, int SY, int FX, int FY) {
	if (SX == FX && SY == FY) {
		total++;//出口
		return;
	}
	else if (SX == -1 || SY == -1 || SX > N || SY > M) return;
	else if (vis[SX][SY] == 0&&map[SX][SY]!=-1) {
		vis[SX][SY] = 1;
		for (int i = 0; i < 4; i++) {
			dfs(SX + dx[i], SY + dy[i], FX, FY);
		}
		vis[SX][SY] = 0;
	}
}


int main() {
	int SX, SY, FX, FY;
	scanf("%d %d %d", &N, &M, &T);
	scanf("%d %d %d %d", &SX, &SY, &FX, &FY);
	//初始化数组
	for (int i = MAXSIZE - 1 - N; i <= MAXSIZE - 1; i++) {
		for (int j = MAXSIZE - 1 - M; j <= MAXSIZE - 1; j++) {
			map[i][j] = -1;
		}
	}
	//障碍物标记为-1
	for (int i = 1; i <= T; i++) {
		int T_x, T_y;
		scanf("%d %d", &T_x, &T_y);
		map[T_x][T_y] = -1;
	}
	dfs(SX, SY, FX, FY);
	if (flag == false)printf("no\n");
	else printf("yes\n");
}
