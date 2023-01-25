#include<stdio.h>
#include<stdlib.h>
#define LEN 50005
#pragma warning(disable : 4996)

typedef struct process {
	char name[100];
	int time;
}process;

typedef struct queue {
	int tail;
	int head;
	process* P;
};
typedef struct queue* Queue;

Queue initQueue() {
	Queue q = malloc(sizeof(struct queue));
	q->tail = 0;
	q->head = 0;
	q->P = malloc(sizeof(process) * LEN);
	return q;
}
void enqueue(Queue q,process p) {
	q->P[q->tail] = p;
	q->tail = (q->tail + 1) % LEN;
}


process dequeue(Queue q) {
	process  p= q->P[q->head];
	q->head = (q->head + 1) % LEN;
	return p;
}

int main() {
	int elaps = 0, c;
	int i,a,n;
	process u;
	Queue q = initQueue();
	scanf("%d %d", &n, &a);

	for (i = 1; i <= n; i++) {
		scanf("%s",&q->P[i].name );
		scanf("%d", &q->P[i].time);
	}
	q->head = 1; q->tail = n + 1;
	while (q->head != q->tail) {
		u = dequeue(q);
		c = min(a, u.time);
		u.time -= c;
		elaps += c;
		if (u.time > 0)enqueue(q,u);
		else
		{
			printf("%s %d\n", u.name, elaps);
		}
	}
	return 0;
}