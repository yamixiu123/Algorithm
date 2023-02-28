#include<stdio.h>
int A[2000000] = {-1};
int H = 1;
#pragma warning(disable : 4996)

int get_parent(int i) {
	if (i == 1) return 1;
	else if (i % 2 == 0) return i / 2 ;
	else return (i-1) / 2 ;

}

void maxHeapify(int i) {
	int p = get_parent(i);
	if (A[i] > A[p]) {
		int temp = A[p];
		A[p] = A[i];
		A[i] = temp;
		maxHeapify(p);
	}
}

void heapInsert(int j) {
	A[H] = j;
	//×î´ó¶Ñ»¯
	maxHeapify(H);
	H++;
}

void heapify(int p) {
	int l_child = p * 2;
	int r_child = p * 2 + 1;
	int largest;
	if (l_child >= H) { return;}
	else if (r_child >= H||A[r_child]<A[l_child]) {
		largest = l_child;
	}
	else {
		largest = r_child;
	}
	if (A[p] < A[largest]) {
		int temp;
		temp = A[p];
		A[p] = A[largest];
		A[largest] = temp;
		heapify(largest);
	}
}



void extract(int p) {
	A[H] = A[p];
	A[p] = A[H-1];
	heapify(p);
}

int main() {
	while (1) {
		char cmd[10];
		scanf("%s", cmd);
		if (cmd[0] == 'i') {
			int j;
			scanf("%d",&j);
			heapInsert(j);
		}
		else if (cmd[0] == 'e' && cmd[1] == 'x') { 
		extract(1);
		printf("%d\n", A[H]);
		H--;
		}
		else if (cmd[0] == 'e' && cmd[1] == 'n'){ break; }
	}

	return 0;
}