#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int t, n, a[1000003];
int m[10000003];
long long bit[1000003];
long long sol;

void set(int x) {
    for(; x < n; x += x & -x) bit[x]++;
}

long long sum(int x) {
    long long ret = 0;
    for(; x; x -= x & -x) ret += bit[x];
    return ret;
}

int main()
{
    sol = 0;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        m[a[i]] = n - i;
    }
    sort(a, a + n);
    for(i = 0; i < n; ++i) {
        set(m[a[i]]);
        sol += sum(m[a[i]] - 1);
    }
    printf("%lld\n", sol);
    return 0;
}

