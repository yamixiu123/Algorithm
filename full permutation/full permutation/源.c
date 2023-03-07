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
	//6.����
	if(dep==n)
	{
		for (int i = 0; i < dep; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n", ans[i]);
		return;
	}
	//1.ö�ٷ�����
	for (int i = 0; i < n; i++) {
		if (color[i] != black) {
			//2,�����Ƿ�Ҫ��ֹ�������� ��Ҫ�򿪱������
			color[i] = black;
			//3.������ǰ��
			ans[dep] = num[i];
			//4.������һ��3
			dfs(dep + 1, n);
			//5.����-��ԭ���״̬
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