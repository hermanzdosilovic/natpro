#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int n, q, x, y;
ll z;
char s[10];
ll a[100005];
ll tree[1<<20];
int l[1<<20];
int r[1<<20];
int leaf[100005];

void init(int lo, int hi, int x) {
    l[x] = lo;
    r[x] = hi;
    if(lo == hi) {
        leaf[lo] = x;
        tree[x] = a[lo];
        return;
    }
    init(lo, lo + (hi - lo) / 2, 2*x);
    init(lo + (hi - lo) / 2 + 1, hi, 2*x+1);
    tree[x] = min(tree[2*x], tree[2*x+1]);
}

void update(int x) {
    if(x == 0)
        return;
    tree[x] = min(tree[2*x], tree[2*x+1]);
    update(x/2);
}

void add(int x, ll v) {
    tree[x] = v;
    update(x/2);
}

bool go(int x, int lo, int hi)
{
    return l[x] >= lo && r[x] <= hi ||
            lo >= l[x] && lo <= r[x] ||
            hi >= l[x] && hi <= r[x];
}

ll query(int lo, int hi, int x)
{
    if(l[x] >= lo && r[x] <= hi)
        return tree[x];
    ll ret = -1;
    int nx = 2*x;
    if(go(nx, lo, hi))
        ret = query(lo, hi, nx);
    ++nx;
    if(go(nx, lo, hi)) {
        if(ret == -1)
            ret = query(lo, hi, nx);
        else
            ret = min(ret, query(lo, hi, nx));
    }
    return ret;
}


int main()
{
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    init(1, n, 1);
    scanf("%d", &q);
    while(q--) {
        scanf(" %s %d", s, &x);
        if(s[0] == 's') {
            scanf("%d", &y);
            cout << query(x, y, 1) << endl;
        }
        else {
            scanf("%lld", &z);
            add(leaf[x], z);
        }
    }
    return 0;
}

/*
5
5 4 3 2 1
3
s 1 4
p 4 4
s 1 4
*/
