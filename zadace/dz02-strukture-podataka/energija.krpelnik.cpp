#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

struct node
{
    ll mink, maxk;
    node(ll a, ll b)
    {
        mink = a;
        maxk = b;
    }
    node()
    {
    }
};

int L;
ll R;
int i;
ll j;
char qstr[10];
int l[1<<20], r[1<<20];
node tree[1<<20];
int leaf[100001];
set<int> s;

ll mini(ll a, ll b)
{
    if(a == -1)
        return b;
    if(b == -1)
        return a;
    return min(a, b);
}

void init(int lo, int hi, int x)
{
    tree[x] = node(-1, 0);
    l[x] = lo;
    r[x] = hi;
    if(lo == hi)
    {
        leaf[lo] = x;
        return;
    }
    init(lo, lo + (hi - lo) / 2, 2*x);
    init(lo + (hi - lo) / 2 + 1, hi, 2*x+1);
}

void update(int x)
{
    tree[x].mink = mini(tree[2*x].mink, tree[2*x+1].mink);
    tree[x].maxk = max(tree[2*x].maxk, tree[2*x+1].maxk);
    if(x == 1)
        return;
    update(x/2);
}

void add(int x, ll val)
{
    tree[x].mink = val;
    tree[x].maxk = val;
    update(x/2);
}

void del(int x)
{
    tree[x].mink = -1;
    tree[x].maxk = 0;
    update(x/2);
}

bool go(int nx, int lo, int hi)
{
    return l[nx] >= lo && r[nx] <= hi ||
       lo >= l[nx] && lo <= r[nx] ||
       hi >= l[nx] && hi <= r[nx];
}

ll queryMin(int lo, int hi, int x)
{
    if(l[x] >= lo && r[x] <= hi)
        return tree[x].mink;

    ll rez = -1;
    int nx = 2*x;

    if(go(nx, lo, hi))
        rez = queryMin(lo, hi, nx);
    nx++;
    if(go(nx, lo, hi))
        rez = mini(rez, queryMin(lo, hi, nx));
    return rez;
}

ll queryMax(int lo, int hi, int x)
{
    if(l[x] >= lo && r[x] <= hi)
        return tree[x].maxk;

    ll rez = 0;
    int nx = 2*x;

    if(go(nx, lo, hi))
        rez = queryMax(lo, hi, nx);
    nx++;
    if(go(nx, lo, hi))
        rez = max(rez, queryMax(lo, hi, nx));
    return rez;
}

int main()
{
    scanf("%d", &L);
    init(1, L, 1);
    while(true)
    {
        scanf(" %s", qstr);
        if(qstr[0] == 'A')
        {
            scanf("%d %lld", &i, &j);
            i++;
            add(leaf[i], j);
            s.insert(i);
        }
        else if(qstr[0] == 'D')
        {
            scanf("%d", &i);
            i++;
            del(leaf[i]);
            s.erase(i);
        }
        else if(qstr[0] == 'Q')
        {
            scanf("%lld", &R);
            if(s.empty())
            {
                printf("0\n");
                continue;
            }
            int lo = *s.begin(), hi = L, mid, pos;
            ll qMax, qMin;
            set<int>::iterator it;
            while(lo < hi)
            {
                mid = lo + (hi - lo) / 2 + 1;
                qMax = queryMax(1, mid, 1);
                qMin = queryMin(1, mid, 1);
                if((qMax - qMin) * ((ll)mid-1) <= R)
                    lo = mid;
                else
                    hi = mid-1;
            }
            it = s.lower_bound(lo);
            if(*it == lo)
                cout << (*it) - 1 << endl;
            else
                cout << (*--it) - 1 << endl;
        }
        else
            break;
    }
    return 0;
}
