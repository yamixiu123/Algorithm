#include<stdio.h>
#include<stdlib.h>
#define NIL -1
struct Node;
typedef struct Node* node;
#pragma warning(disable : 4996)

struct Node{
	int key;
    node parent, left_c, right_c;
};
node create_tree() {
    node root = malloc(sizeof(struct Node));
    root->key = NIL;
    root->parent = NULL;
    root->left_c = NULL;
    root->right_c = NULL;
    return root;
}

void insert(node *root,int key) {
    if (*root == NULL) {
         *root = malloc(sizeof(struct Node));
        (*root)->key = key;
        (*root)->parent = NULL;
        (*root)->left_c = NULL;
        (*root)->right_c = NULL;
    }
    else if (key > (*root)->key) {
        insert(&(*root)->right_c, key);
     }
    else if (key < (*root)->key) {
        insert(&(*root)->left_c, key);
    }
}
void inorder(node root) {
    if (root->left_c != NULL) inorder(root->left_c);
    printf(" %d", root->key);
    if (root->right_c != NULL)inorder(root->right_c);
}
void preorder(node root) {
    printf(" %d", root->key);
    if (root->left_c != NULL) preorder(root->left_c);
    if (root->right_c != NULL)preorder(root->right_c);
}

int main() {
	int c_num,key;
	scanf("%d", &c_num);
	char com[20];

    node root = NULL;
	for (int i = 0; i < c_num; i++) {
		scanf("%s", com);
        if (com[0] == 'i') {
            scanf("%d", &key);
            insert(&root,key);
        }
        else if (com[0] == 'p') {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
	}

	return 0;
}