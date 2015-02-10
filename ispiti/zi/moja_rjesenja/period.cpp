#include <cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 500000;
const llint MOD = 1000003;
const llint B = 17;

llint b[MAXN + 2];
llint h[MAXN + 2];

int N;
char niz[MAXN + 2];

llint mod(llint x) {
    return (x%MOD + MOD)%MOD;
}

llint hash(int x, int y) {
    return mod(h[y] - mod(h[x - 1]*b[y - x + 1]));
}

int main() {
    scanf("%d%s", &N, niz);
    b[0] = 1;
    h[0] = niz[0];
    for (int i = 1; i < N; i++) {
        h[i] = mod(mod(B*h[i - 1]) + niz[i]);
        b[i] = mod(B*b[i - 1]);
    }
    int sol = N;
    for (int len = 1; len <= N; len++) {
        for (int i = len; i < N; i += len) {
            if (i + len >= N) {
                if (hash(0, N - i - 1) == hash(i, N - 1)) {
                    sol = len;
                    len = i = N; // double loop break
                }
            } else {
                if (hash(0, len - 1) != hash(i, i + len - 1))
                    break;
            }
        }
    }
    printf("%d\n", sol);
    return 0;
}
