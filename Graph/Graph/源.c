#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 101
#pragma warning(disable : 4996)

int G[101][101];
//queue function 


int d[MAXSIZE];//标记数组
int f[MAXSIZE] = {0};
int S[MAXSIZE] = {0};
int Q[100] = {0};
int rear = 0;
int front = 0;
int index=0;
int count = 0;

int isEmpty() {
	if (count == 0)return 1;
	else return 0;
}

void enqueue(int i) {
	if (count != MAXSIZE - 1) {
		Q[rear++] = i;
		count++;
	}
	else
	{
		printf("stack over flow");
	}
}

int  dequeue() {
	if (count!=0) {
		int i = Q[front++];
		count--;
		return i;
	}
	else {
		printf("queue is empty");
		return; 
	}

}
//队列实现
void bfs(int i, int n) {
	int depth = 0;//标记防止重复 检索d [i]放入距离
	enqueue(i);
	d[i] = 0;	//入队
	while (count!=0) {
		int tmp = dequeue();
		depth = d[tmp];
		for (int k = 1; k <= n; k++) {//遍历邻接点
			if (G[tmp][k] == 1 && d[k] == -1) {
				d[k] = depth+1;//入队前先标记！
				enqueue(k);
			}	//邻接点入队
		}
	}
}

int main() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			G[i][j] = 0;
		}
	}
	int n;
	scanf("%d", &n);
	int row, column;
	int c_num;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &row, &c_num);
		for (int j = 1; j <= c_num; j++) {
			scanf("%d", &column);
			G[row][column] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		d[i] = -1;
	}
	bfs(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n",i, d[i]);
	}

}
