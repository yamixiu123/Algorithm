#include<stdio.h>
#include<stdbool.h>
#define SIZE 36
#pragma warning(disable : 4996)


typedef struct card {
	char suit;
	int num;
}card;

void bubbleSort(card C[],int N){
	bool flag = true;
	card temp;
	while (flag) {
		flag = false;
		for (int i = 0; i < N-1; i++) {
			if (C[i].num > C[i + 1].num) {
				temp = C[i];
				C[i] = C[i + 1];
				C[i + 1] = temp;
				flag = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%C%d", C[i].suit, C[i].num);
		if (i < N - 1) printf(" ");
		else printf("\n");
	}
	printf("Stable\n");
}
void selectionSort(card C[],card D[], int N) {
	bool flag = false;
	int minj,j;
	card temp;
	for (int i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (D[j].num < D[minj].num) {
				minj = j;
			}
		}
		temp = D[i];
		D[i] = D[minj];
		D[minj] = temp;
	}

	for (int i = 0; i < N; i++) {
		printf("%C%d", D[i].suit,D[i].num);
		if (i < N - 1) printf(" ");
		else printf("\n");
	}

	for (int i = 0; i < N; i++) {
		if (D[i].suit == C[i].suit) continue;
		else {
			flag = true;
			break;
		}
	};

	if (flag)printf("Not stable\n");
	else printf("Stable\n");
}


int main() { 
	int N;
	scanf("%d\n", &N);
	card C[36];
	card D[36];

	for (int i = 0; i < N; i++) {
		scanf("%C%d", &C[i].suit, &C[i].num);
		getchar();
	}
	for (int i = 0; i < N; i++) {
		D[i] = C[i];
	}
	bubbleSort(C, N);
	selectionSort(C,D, N);	
	return 0;
}
