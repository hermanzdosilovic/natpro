#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int x[100003];

double f(double pos)
{
    double sum = 0;
    for(int i = 0; i < n; ++i)
        sum += (x[i] - pos) * (x[i] - pos);
    return sum;
}

int main()
{
    scanf("%d", &n);
    int i;
    double lo = 1 << 30, hi = 0, l, r;
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &x[i]);
        if(x[i] < lo)
            lo = x[i];
        if(x[i] > hi)
        hi = x[i];
    }
    while(abs(hi - lo) > 1e-6)
    {
        l = lo + (hi - lo) / 3;
        r = hi - (hi - lo) / 3;
        if(f(l) < f(r))
            hi = r;
        else
            lo = l;
    }
    printf("%.3lf\n", f((lo+hi)/2));
    return 0;
}
