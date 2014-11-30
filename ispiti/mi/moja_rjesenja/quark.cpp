#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long lld;
typedef pair<lld, lld> pll;

vector<pll> n;
vector<lld> m;

int main(void) {
	lld N, K;
	lld a, b;
	scanf("%lld%lld", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &a, &b);
		n.push_back(mp(a, a+b));
	}
	for (int i = 0; i < N; i++) {
		lld x = n[i].x;
		lld y = n[i].y;
		for (int k = x; k < y; k++)
			m.push_back(k);
	}
	sort(m.begin(), m.end());
	printf("%lld\n", m[K-1]);
	return 0;
}
