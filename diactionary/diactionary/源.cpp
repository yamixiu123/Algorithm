#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable : 4996)
int A[100000] = {NULL};
int ran[] = { 1,7,13,17,19,23,29,31,37,41,43,47,51,53 };
int  trace(int a,int d){
	int hash = a*(ran[d]);
	return hash;
}
bool find(int hash,char*key,int i){
	if (A[hash] == NULL) return false;
	int* b = A[hash];
	int j;
	while (b != NULL) {
		for (j = 0; j < i; j++) {
			if (b[j] != (int)key[j]) {
				b = A[++hash];
				break;
			}
		}
		if (j == i) return true;
	}
	return false;

}

int main() {
	int n;
	scanf("%d",&n);
	char cmd[10];
	for (int i = 0; i < n; i++) {
		int hash = 0;
		char key[12];
		scanf("%s",cmd);
		if(strcmp(cmd,"insert")==0){
			int* j =(int*) malloc(sizeof(int) * 12);
			scanf("%s", key);
			int i = 0;
			while (key[i] == 'A' || key[i] == 'C' || key[i] == 'G' || key[i] == 'T') {
				hash += trace(key[i], i);
				j[i] = key[i];
				i++;
			}
			while (A[hash] != NULL) {
				hash = hash + 1;
			}
			A[hash] = j;
		}
		else{
			scanf("%s", key);
			int i = 0;
			while (key[i] == 'A' || key[i] == 'C' || key[i] == 'G' || key[i] == 'T') {
				hash += trace(key[i], i);
				i++;
			}
			if (find(hash,key, i)) printf("yes\n");
			else printf("no\n");
		}
		
	}
	return 0;
}