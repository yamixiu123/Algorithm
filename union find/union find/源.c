#include<stdio.h>
#define MAXSIZE 100000
#pragma warning(disable : 4996)

int parent[MAXSIZE];
int rank[MAXSIZE];
int m, n,q;

void initiate(int n) {
	for (int i=0;i<n;i++)
	{	
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int i) {
	if (parent[i] == i) return i;
	else
	{
		parent[i] = find(parent[i]);
		return parent[i];
	}
}

int merge(int x, int y) {
	int rootX = find(x);//parent
	int rootY = find(y);
	if (rootX != rootY) {
		if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	initiate(m);
	for (int i = 0; i < n; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		merge(s, t);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		int p1 = find(s);
		int p2 = find(t);
		if (p1 == p2)printf("yes\n");
		else printf("no\n");
	}
}