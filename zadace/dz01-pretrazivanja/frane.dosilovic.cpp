#include <cstdio>
#include <cmath>

int x[100002];
int N;

double len(double k)
{
    double s = 0;
    for(int i = 0; i < N; i++)
        s += fabs(x[i] - k)*fabs(x[i] - k);
    return s;
}

int main()
{
    double lo = 1, hi = 100002;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
    }

    double t1, t2;
    while(hi - lo > 1e-5)
    {
        t1 = lo + (hi - lo)/3;
        t2 = lo + 2*(hi - lo)/3;
        if(len(t2) - len(t1) > 1e-5)
            hi = t2;
        else
            lo = t1;
    }
    printf("%.3lf\n", len(lo));
    return 0;
}
