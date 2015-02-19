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
#include <iostream>
#include <cstdio>

int n;
int x1[100000], x2[100000];
int y1[100000], y2[100000];
double lo = 1 << 30, hi, mid;
double ukupna_pov;

double aps(double x)
{
    return x < 0 ? -x : x;
}

double pov_lijevo(double x)
{
    double pov = 0;
    for(int i = 0; i < n; ++i)
    {
        if((double)x2[i] <= x)
            pov += (x2[i] - x1[i]) * (y2[i] - y1[i]);
        else if((double)x1[i] < x && (double)x2[i] > x)
            pov += (x - (double)x1[i]) * (y2[i] - y1[i]);
    }
    return pov;
}

double rijesi()
{
    while((hi - lo) > 1e-6)
    {
        mid = lo + (hi - lo) / 2;
        double pov = pov_lijevo(mid);
        if(aps(ukupna_pov - 2*pov) < 0.001)
            return mid;
        else if(2*pov < ukupna_pov)
            lo = mid;
        else
            hi = mid;
    }
    return -1;
}


int main()
{
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; ++i)
    {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        ukupna_pov += (x2[i] - x1[i]) * (y2[i] - y1[i]);
        if(x1[i] < lo)
            lo = x1[i];
        if(x2[i] > hi)
            hi = x2[i];
    }
    printf("%lf\n", rijesi());
    return 0;
}
