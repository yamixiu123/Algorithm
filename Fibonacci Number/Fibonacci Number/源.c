#include<stdio.h>
#pragma warning(disable : 4996)

int dp[50] = { 0 };
int Fibonacci_Number(int n) {
	if (n == 0 || n == 1)return dp[n] = 1;
	if (dp[n] != 0)return dp[n];
	else return dp[n] = Fibonacci_Number(n - 1) + Fibonacci_Number(n - 2);
}
int main() {
	int n ,res;
	scanf("%d", &n);
	res = Fibonacci_Number(n);
	printf("%d\n", res);
	return 0;
}