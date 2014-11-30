#include <cstdio>
#include <set>

using namespace std;

multiset<int> s;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		s.insert(a);
		if(i >= M)
			s.erase(s.begin());
		printf("%d\n", *s.begin());
	}
	return 0;
}
