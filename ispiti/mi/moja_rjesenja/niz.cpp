#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int n[MAXN + 3];
int g[MAXN + 3];
 
int main(void) {
	int N, G;
	scanf("%d%d", &N, &G);
	for (int i = 0; i < N; i++) {
		scanf("%d", n + i);
	}
	
	if (N == 1)
		g[0] = n[0];

	for (int i = 1; i < N; i++) {
		g[i - 1] = gcd(max(n[i], n[i - 1]), min(n[i], n[i - 1]));
	}

	int len = 0, maxlen = 0;
	for (int i = 0; i < N - 1; i++) {
		if (g[i] != G) {
			len = 0;	
		} else {
			len++;
			maxlen = max(maxlen, len);		
		}
	}
	
	if (N != 1)
		printf("%d\n", maxlen + (maxlen > 0));
	else
		printf("%d\n", n[0] == G);

	return 0;
}
