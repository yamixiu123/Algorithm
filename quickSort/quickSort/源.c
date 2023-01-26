#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct card {
	char name[10];
	int num;
}Card;

Card A[100000] = {NULL};
Card B[100000] = {NULL};
int n;

int partition(Card A[],int left,int pivot){
	int j = left - 1;
	int i = left;
	for(;i<pivot;i++){
		if (A[i].num <= A[pivot].num) {
			j++;
			Card temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		} 
	}
	Card temp = A[i];
	A[i] = A[j+1];
	A[j+1] = temp;

	return j + 1;
}

void quickSort(Card A[],int left,int right){
	int pivot;
	if (left < right) {
		pivot = partition(A, left, right);
		quickSort(A, left, pivot-1);
		quickSort(A, pivot + 1, right);
	}
}

void merge(Card tArr[],Card B[], int left, int mid, int right){
	int l_pos = left;
	int r_pos = mid + 1;
	int t_pos = left;

	while (l_pos <= mid && r_pos <= right) {
		if (B[l_pos].num <= B[r_pos].num)
			tArr[t_pos++] = B[l_pos++];
		else
			tArr[t_pos++] = B[r_pos++];
	}
	while (l_pos <= mid)
		tArr[t_pos++] = B[l_pos++];
	while (r_pos <= right)
		tArr[t_pos++] = B[r_pos++];
	while (left <= right) {
		B[left] = tArr[left++];
	}	
}

void mSort(Card tArr[],Card B[],int left,int right){
	int center;
	if (right > left) {
		center = (left + right) / 2;
		mSort(tArr, B, left, center);
		mSort(tArr, B, center + 1, right);
		merge(tArr, B, left, center, right);
	}
}

void mergeSort(Card B[]) {
	Card* temp = malloc(sizeof(struct card) * 100000);
	mSort(temp, B, 0, n - 1);
}

int main() {
	bool flag = true;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &A[i].name);
		scanf("%d", &A[i].num);
		getchar();
		B[i] = A[i];
	}
	quickSort(A,0,n-1);
	mergeSort(B);
	for (int i = 0; i < n; i++) {
		if (A[i].name[0] != B[i].name[0] || A[i].num != B[i].num) flag = false;
	}
	if (flag) {
		printf("Stable\n");
	}
	else printf("Not stable\n");
	
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", A[i].name, A[i].num);
	}

	return 0;
}