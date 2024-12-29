#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
/*
27433_팩토리얼2
1112KB	0ms
*/
#include <cstdio>

long long int factorial(int n) {
	if (n < 2) return 1;
	return n * factorial(n - 1);
}

int main() {
#ifdef _WIN32
	freopen("input.txt", "r", stdin);
#endif // _WIN32
	int N;
	scanf("%d", &N);
	printf("%lld\n", factorial(N));
	return 0;
}
