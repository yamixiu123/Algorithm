#include<stdio.h>
#define Nil -1
#define Max 100000

struct Node{ int parent,left_child,right_sibling};
typedef struct Node node;

int node_num;
node T[Max];

int main() {
	scanf("%d", &node_num);
	node root;
	root.left = Nil;
	root.parent = Nil;
	root.right = Nil;
	root;
	T[0] = root;
	for (int i = 0; i < n; i++) {
		int temp;
		int child_num;
		scanf("%d", &temp);
		scanf("%d", &child_num);
		scanf("%d",&T[i].left_child)
		for (int j = 1; j < child_num; j++) {
			
		}
	}
	return 0;
}