#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

A[500000];
int count = 0;
/*Merge*/
void merge(int tempArr[], int left, int mid,int right){
	/*Unsort index*/
	int l_pos = left;
	int r_pos = mid+1;
	/*The index of tempArr*/
	int t_pos = left;

	/*merge*/
	while (l_pos <= mid && r_pos <=right ) {
		count++;
		if (A[l_pos] < A[r_pos]) {
			tempArr[t_pos++] = A[l_pos++];
		}
		else {
			tempArr[t_pos++] = A[r_pos++];
		}
	}
	
	/*merge remaining elements*/
	while (l_pos <= mid) {
		count++;
		tempArr[t_pos++] = A[l_pos++];
	}
	while (r_pos <= right) {
		count++;
		tempArr[t_pos++] = A[r_pos++];
	}
	/*Transfer tempArr elements to Arr*/
	while (left <= right) {
		A[left] = tempArr[left++];
	}
}
/*Devide*/
void msort(int tempArr[],int left,int right) {
	int center;
	if (right > left) {
		count++;
		center = (right + left) / 2;
		msort(tempArr, left, center);
		msort(tempArr, center + 1, right);
		merge(tempArr, left, center, right);
	}
}

/*Entrance*/
void mergeSort(int n) {
	int* tempArr;
	tempArr = malloc(sizeof(int) * n);
	msort(tempArr, 0,n-1);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	mergeSort(n);
	for (int i = 0; i < n; i++) {
		if (i<n-1)
		{
			printf("%d ", A[i]);
		}
		else {
			printf("%d\n", A[i]);
		}
	}
	printf("%d\n", count);
	return 0;
}