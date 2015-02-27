#include<iostream>
#include<cstdio>

int n;
int x[200003];
int c[2000003];
int maks;
long long sol;

int main()
{
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        c[x[i]]++;
        if(maks < x[i])
            maks = x[i];
    }
    int v;
    for(i = 1; i <= maks; ++i) {
        v = 0;
        for(j = i; j <= maks; j += i) {
            v += c[j];
        }
        if(v >= 2 && (long long)v*i > sol)
            sol = (long long)v*i;
    }
    printf("%lld\n", sol);
    return 0;
}
