#include <stdio.h>

int N;

int f(int r) {
	int sol = 1;
	int M = N;
	int k = M/r + 1;
	while (M > 0) {
		if (M - k > 0)
			sol *= k;
		else {
			sol *= M;
			break;	
		}
		M -= k;
	}
	int sol2 = 1;
	M = N;
	k = M/r;
	while (M > 0) {
		if (M - k > 0)
			sol2 *= k;
		else {
			sol2 *= M;
			break;
		}
		M -= k;	
	}
	return sol > sol2 ? sol : sol2;
}

int main(void) {
	scanf("%d", &N);
	int lo = 1, mid, hi = N;
	int max = N;
	while (lo < hi) {
		mid = lo + (hi - lo)/2;
		int a = f(mid);
		if (a >= max) {
			max = a;
		}
		hi = mid;
	}
	printf("%d\n", max);
	return 0;
}
