#include <cstdio>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long lld;

const int MAX_N = 1000000;

lld lg[MAX_N + 3];
int N;
pair<int, int> a[MAX_N + 3];

lld sum(int x) {
    lld sol = 0;
    for(; x > 0; x -= x & -x) {
        sol += lg[x];
    }
    return sol;
}

void update(int x) {
    for(; x <= N; x += x & -x) {
        lg[x] += 1;
    }
}

int main() {
    lld sol = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i].x);
        a[i].y = N - i;
    }
    sort(a, a + N);
    for(int i = 0; i < N; i++) {
        sol += sum(a[i].y);
        update(a[i].y);
    }
    printf("%lld\n", sol);
    return 0;
}
