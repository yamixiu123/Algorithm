#include<stdio.h>
#define MAXSIZE 10000
int num[MAXSIZE];
int ans[MAXSIZE];
enum {
	white = 0,black
};
int color[MAXSIZE];
int num[MAXSIZE];
void dfs(int dep,int n) {
	//6.结束
	if(dep==n)
	{
		for (int i = 0; i < dep; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n", ans[i]);
		return;
	}
	//1.枚举方案数
	for (int i = 0; i < n; i++) {
		if (color[i] != black) {
			//2,考虑是否要防止重新搜索 需要则开标记数组
			color[i] = black;
			//3.搜索当前层
			ans[dep] = num[i];
			//4.进入下一层3
			dfs(dep + 1, n);
			//5.回溯-还原相关状态
			color[i] = white;
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		color[i] = white;
	}
	dfs(0, n);
}