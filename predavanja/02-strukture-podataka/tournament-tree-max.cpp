// Herman Zvonimir Došilović
/*
Treba ispisati maksimalni element u nekom podnizu. Postoje dva querya update i query.
update postavlja vrijednost nekog elementa na unesenu vrijednost.
Query a b vraca maksimalni broj u intervalu [a, b]
*/
#include <cstdio>

const int MAX_N = 1000003;

int tree[(1 << 21) + 3], a[MAX_N], N, M;
int x, y;

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

void init(int n, int l, int r) {
    if(l == r) {
        tree[n] = a[l];
        return;
    }
    init(2*n, l, (l + r)/2);
    init(2*n + 1, (l + r)/2 + 1, r);
    tree[n] = max(tree[2*n], tree[2*n + 1]);
}

int query(int n, int l, int r) {
    if(l > y || r < x) {
        return 0x80000000;
    }
    if(l >= x && r <= y) {
        return tree[n];
    }
    int q = query(2*n, l, (l + r)/2);
    int p = query(2*n + 1, (l + r)/2 + 1, r);
    return max(p, q);
}

void update(int n, int l, int r) {
    if(l > y || r < x) {
        return;
    }
    if(l == r && r == x) {
        tree[n] = y;
        return;
    }
    else if(l == r) {
        return;
    }
    update(2*n, l, (l + r)/2);
    update(2*n + 1, (l + r)/2 + 1, r);
    tree[n] = max(tree[2*n], tree[2*n + 1]);
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
        if(c == 'Q') {
            printf("%d\n", query(1, 0, N - 1));
        } else {
            a[x] = y;
            update(1, 0, N - 1);
        }
    }

    return 0;
}
