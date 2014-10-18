/*
Trazenje sume na intervalu s updateom.
*/
#include <cstdio>

const int MAX_N = 1000003;

int tree[(1 << 21) + 3], a[MAX_N], N, M;
int x, y;


int query(int n, int l, int r) {
    if(l > y || r < x) {
        return 0;
    }
    if(l >= x && r <= y) {
        return tree[n];
    }
    int q = query(2*n, l, (l + r)/2);
    int p = query(2*n + 1, (l + r)/2 + 1, r);
    return p + q;
}

void init(int n, int l, int r) {
    if(l == r) {
        tree[n] = a[l];
        return;
    }
    init(2*n, l, (l + r)/2);
    init(2*n + 1, (l + r)/2 + 1, r);
    tree[n] = tree[2*n] + tree[2*n + 1];
}

void update(int n, int l, int r) {
    if(l > y || r < x)
        return;
    if(l == r && x == r) {
        tree[n] = y;
        return;
    }
    else if(l == r) {
        return;
    }
    update(2*n, l, (l + r)/2);
    update(2*n + 1, (l + r)/2 + 1, r);
    tree[n] = tree[2*n] + tree[2*n + 1];
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    init(1, 0, N - 1);
    for(int i = 0; i < M; i++) {
        char c;
        scanf(" %c%d%d", &c, &x, &y);
        if(c == 'U') {
            a[x] = y;
            update(1, 0, N - 1);
        } else {
            printf("%d\n", query(1, 0, N - 1));
        }
    }
    return 0;
}
