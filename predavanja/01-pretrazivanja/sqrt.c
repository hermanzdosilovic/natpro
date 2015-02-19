// Herman Zvonimir Došilović
/*
Implementirati funkciju sqrt koristenjem binarnog pretrazivanja.
*/
#include <stdio.h>

int main(void)
{
    double N;
    scanf("%lf", &N);
    double hi = N, lo = 1, mid;
    while(hi - lo > 1e-7)
    {
        mid = lo + (hi - lo) / 2;
        if(mid * mid < N)
            lo = mid;
        else
            hi = mid;
    }
    printf("sqrt(%lf) = %lf\n", N, mid);
    return 0;
}
