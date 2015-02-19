/*
Seljak ima N pravokutnih polja i dva sina. Nakon svoje smrti, seljak
zeli podijeliti ta polja na dva jednaka dijela.
Gdje seljak treba podijeliti polje tako da svaki sin dobije istu povrsinu polja?

Input:
    N pravkutnih polja koja:
        x1, y1 - donji lijevi kut pravokutnika
        x2, y2 - gornji desni kut pravokutnika
Output:
    Koordinata gdje seljak treba presjeci polje.

Zbog jednostavnosti pretpostavljamo:
    x, y >= 0
*/
#include <cstdio>
#define MAXN 1000

int N, maxx;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];

double min(double x, double y)
{
    if (x > y)
        return y;
    return x;
}

int max(int x, int y)
{
    if(x > y)
        return x;
    return y;
}

double pov_lijevu(double k)
{
    double sol = 0;
    for(int i = 0; i < N; i++)
    {
        double a, b;
        b = y2[i] - y1[i];
        a = min(x2[i], k) - x1[i];
        if(x1[i] < k)
            sol += a*b;
    }
    return sol;
}

double rijesi()
{
    double P = 0;
    for(int i = 0; i < N; i++)
        P += (x2[i] - x1[i]) * (y2[i] - y1[i]);
    double lo = 0, hi = maxx, mid;
    while(hi - lo > 1e-3)
    {
        mid = (lo + hi) / 2;
        if(2 * pov_lijevu(mid) < P)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        maxx = max(maxx, x2[i]);
    }
    printf("%.3lf\n", rijesi());
    return 0;
}
