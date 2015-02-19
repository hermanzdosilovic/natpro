// Ivan Krpelnik
#include <iostream>
#include <cstdio>

int tree[1<<20];
int l[1<<20], r[1<<20];

int n, q, a, b;

void init(int lo, int hi, int x)
{
    tree[x] = 0;
    l[x] = lo;
    r[x] = hi;
    if(lo == hi)
        return;
    init(lo, lo + (hi - lo) / 2, x*2);
    init(lo + (hi - lo) / 2 + 1, hi, x*2 + 1);
}

int ubaci(int pos, int val, int x)
{
    int sum;
    if(l[x] == r[x])
    {
        sum = val - tree[x];
        tree[x] = val;
        return sum;
    }

    if(pos <= l[x] + (r[x] - l[x]) / 2)
        sum = ubaci(pos, val, x*2);
    else
        sum = ubaci(pos, val, x*2+1);
    tree[x] += sum;
    return sum;
}

int upit(int lo, int hi, int x)
{
    if(l[x] >= lo && r[x] <= hi)
        return tree[x];
    int sum = 0;
    if(lo >= l[2*x] && lo <= r[2*x] ||
       hi >= l[2*x] && hi <= r[2*x] ||
       l[2*x] >= lo && r[2*x] <= hi)
        sum += upit(lo, hi, 2*x);
    if(lo >= l[2*x+1] && lo <= r[2*x+1] ||
       hi >= l[2*x+1] && hi <= r[2*x+1] ||
       l[2*x+1] >= lo && r[2*x+1] <= hi)
        sum += upit(lo, hi, 2*x+1);
    return sum;
}

int main()
{
    scanf("%d", &n);
    init(1, n, 1);
    scanf("%d", &q);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        ubaci(a, b, 1);
        printf("%d\n", tree[1]);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", upit(a, b, 1));
    }
    return 0;
}

/*
5 5
1 1
2 2
3 3
4 4
5 5

*/
