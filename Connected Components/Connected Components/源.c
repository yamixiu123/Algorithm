#pragma warning(disable : 4996)
#define MAXSIZE 100000
#define INF -1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int num;
	struct node* fre;
}arcnode;


int visted[MAXSIZE] = { 0 };
int queue[MAXSIZE];

int q=0, r=0, count = 0;

void enqueue(int i) {
	queue[r%MAXSIZE] = i;
	r++;
	count++;
}

int dequeue() {
	int front = queue[q%MAXSIZE];
	q++;
	count--;
	return front;
}

bool notEmpty(){
	return count != 0;
}

void bfs(int i, arcnode* nodes[], int dye) {
	if(visted[i] != INF)return;
	enqueue(i);
	while (notEmpty()) {
		int tmp = dequeue();
		arcnode* node = nodes[tmp];
		while (node->fre != NULL) {
			node = node->fre;
			if (visted[node->num] == INF) {
				visted[node->num] = dye;
				enqueue(node->num);
			}
		}
	
	}
}


void dfs(int i,arcnode* nodes[],int dye) {
	if (visted[i] != INF) return;//to avoid repeat dye 
	visted[i] = dye;
	arcnode* tmp = nodes[i];
	while (tmp->fre != NULL) {
		tmp = tmp->fre;
		dfs(tmp->num, nodes, dye);
	}
}



void initiate(int n) {
	for (int i = 0; i < n; i++) {
		visted[i] = -1;
	}
}

int main() {
	arcnode** nodes = malloc(sizeof(arcnode*) * 100000);
	int n, m, q;
	scanf(" %d %d", &n, &m);
	initiate(n);
	for (int i = 0; i < n; i++) {
		nodes[i] = malloc(sizeof(arcnode));
		nodes[i]->num = i;
		nodes[i]->fre = NULL;
	}
	for (int i = 0; i < m; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		arcnode* tmp1 = malloc(sizeof(arcnode));
		tmp1->fre = nodes[s]->fre;
		nodes[s]->fre = tmp1;
		tmp1->num = t;

		arcnode* tmp2 = malloc(sizeof(arcnode));
		tmp2->fre = nodes[t]->fre;
		nodes[t]->fre = tmp2;
		tmp2->num = s;
	}
	scanf("%d", &q);
	/*dye*/
	for (int i = 0; i < n; i++) {
		bfs(i,nodes,i);
	}
	for (int i = 0; i < q; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		if (visted[s]!=INF&&visted[s]==visted[t]) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}