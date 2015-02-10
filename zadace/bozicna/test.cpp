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

bool bio[1000000 + 3];

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
    lld sol = 0, unique = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i].x);
        if (!bio[a[i].x]) {
            bio[a[i].x] = true;
        } else {
            unique++;
        }
        a[i].y = N - i;
    }

    int k;
    for (k = 1; k < N; k++) {
        if (a[k].x < a[k - 1].x)
            break;
    }
    if (k == N) {
        printf("0\n");
        return 0;
    }

    sort(a, a + N);
    for(int i = 0; i < N; i++) {
        sol += sum(a[i].y);
        update(a[i].y);
    }
    printf("%lld\n", sol - unique);
    return 0;
}
