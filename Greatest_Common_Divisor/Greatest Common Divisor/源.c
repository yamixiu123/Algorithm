#include<stdio.h>

int main() {
	int a,b,r;
	scanf_s("%d%d",&a,&b);
	
	if (b > a) {
		int temp = b;
		b = a;
		a = temp;
	}
	r = a % b;
	while (r != 0) {
			a = b;
			b = r;
			r = a % b;
	}
	printf("%d", b);

	return 0;
}