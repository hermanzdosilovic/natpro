#include <cstdio>

typedef long long lld;

lld z(lld x)
{
    lld n = 0, y = x, a = 1;
    while(y)
    {
        n++;
        a *= 10;
        y /= 10;
    }
    a /= 10;

    lld sol = (x - a + 1)*n;
    a = 1;
    for(lld i = 1; i < n; i++)
    {
        sol += (a*10 - a)*i;
        a *= 10;
    }

    return sol;
}

int main()
{
    lld N;
    scanf("%lld", &N);

    lld hi = N + 1, lo = 1, mid;
    while(lo < hi)
    {
        mid = lo + (hi - lo)/2;
        if(z(mid) < N)
            lo = mid + 1;
        else
            hi = mid;
    }

    lld k = z(lo) - N + 1;
    lld sol;
    while(k--)
    {
        sol = lo%10;
        lo /= 10;
    }

    printf("%lld\n", sol);
    return 0;
}
