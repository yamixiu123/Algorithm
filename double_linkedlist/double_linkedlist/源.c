#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
struct Node {
	int key;
	struct Node* prev, *next;
};

typedef struct Node* head;
typedef struct Node* node;

head create_dlinked_list() {
	head h = malloc(sizeof(struct Node));
	h->next = h;
	h->prev = h;
	
	return h;
}

void insert(int x,head h) {
	struct Node* temp = h;
	while (temp->next!=h) 	temp = temp->next;
	node n = malloc(sizeof(struct Node));
	temp->next = n;
	n->prev = temp;
	n->next = h;
	n->key = x;
	h->prev = n;
}

void delete(int x, head h) {
	struct Node* temp = h;
	while (temp->next != h&&temp->next->key!=x) 	temp = temp->next;
	if (temp->next == h)return;
	temp = temp->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

void deleteFirst(head h) {
	struct Node* temp = h;
	temp = temp->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

void deleteLast(head h) {
	struct Node* temp = h;
	temp = temp->prev;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

void printList(head h) {
	struct Node* temp = h;
	while (temp->next != h) {
		temp = temp->next;
		printf("%d",temp->key);
		if (temp->next != h)printf(" ");
		else printf("\n");
	}	
}


int main() {
	int count;
	head h = create_dlinked_list();
	char command[20];
	int key;

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%s", command);
		scanf("%d", &key);
		if (strcmp(command,"insert")==0) {
			insert(key, h);
		}
		else if (strcmp(command, "delete")==0) {
			delete(key, h);
		}
		else if (strcmp(command, "deleteFirst")==0) {
			deleteFirst(h);
		}
		else {
			deleteLast(h);
		}
	}
	printList(h);

	return 0;
}