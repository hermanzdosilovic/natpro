#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
const int MAX_A = 10000000;

int lg[MAX_A + 3], a[MAX_N + 3], n, N;

int sum(int x) {
    int sol = 0;
    for(; x > 0; x -= x & -x) {
        sol += lg[x];
    }
    return sol;
}

void update(int x, int y) {
    for(; x <= N; x += x & -x) {
        lg[x] += y;
    }
}

int main() {
    int sol = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        N = max(a[i], N);
    }
    for(int i = n - 1; i >= 0; i--) {
        sol += sum(a[i]);
        update(a[i], 1);
    }
    printf("%d\n", sol);
    return 0;
}
