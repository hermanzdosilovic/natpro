#include <iostream>
#include <cstdio>

int m, k;
int x[505];
long long lo, hi, mid;
bool b[505];

bool moze(long long t)
{
    int p = 0;
    long long suma = 0;
    for(int i = 0; i < m; ++i)
    {
        if(suma + x[i] > t)
        {
            suma = 0;
            p++;
        }
        if(p >= k)
            return 0;
        suma += x[i];
    }
    return 1;
}

int main()
{
    scanf("%d %d", &m, &k);
    int i;
    for(i = 0; i < m; ++i)
    {
        scanf("%d", &x[i]);
        if(x[i] > lo)
            lo = x[i];
        hi += x[i];
    }
    while(lo < hi)
    {
        mid = lo + (hi - lo) / 2;
        if(moze(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    int p = k;
    long long suma = 0;
    for(i = m - 1; i >= 0; --i)
    {
        if(suma + x[i] > hi)
        {
            p--;
            b[i+1] = 1;
            suma = 0;
        }
        if(i+1 == p-1)
        {
            for(; i >= 0; --i)
                b[i+1] = 1;
            break;
        }
        suma += x[i];
    }
    for(i = 0; i < m; ++i)
    {
        if(b[i])
            printf("/ ");
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
