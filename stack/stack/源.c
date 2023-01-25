#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000
#pragma warning(disable : 4996)



typedef struct Stack {
	int *A;
	int top;
}Stack;

Stack* createStack() {
	Stack* S = malloc(sizeof(Stack));
	if (S == NULL) printf("Out of memory");
	S->A = malloc(sizeof(int) * SIZE);
	if (S->A == NULL) printf("Out of memory");
	S->top = 0;
	return S;
}
bool isFull(Stack* S) {
	return S->top >= SIZE-1;
};
bool isEmpty(Stack* S) {
	return S->top == 0;
};
int pop(Stack* S) {
	if (isEmpty(S)) {
		printf("Stack is empty\n");
		return;
	}
	return S->A[S->top--];
};
void push(Stack* S, int a) {
	if (isFull(S)) {
		printf("Stack is full\n");
		return;
	}
	S->A[++S->top] = a;
};

int main() {
	Stack* S = createStack();
	char s[1000];
	int a, b;
	while (scanf("%s",s) != EOF)
	{
		if (s[0] == '+') {
			a = pop(S);
			b = pop(S);
			push(S, b + a);
		}
		else if (s[0] == '-') {
			a = pop(S);
			b = pop(S);
			push(S, b - a);
		}
		else if (s[0] == '*') {
			a = pop(S);
			b = pop(S);
			push(S, b * a);
		}
		else if (s[0] == '/') {
			a = pop(S);
			b = pop(S);
			push(S, b / a);
		}
		else{
			push(S, atoi(s));
		}
	}
	printf("%d\n", pop(S));
	return 0;
}
