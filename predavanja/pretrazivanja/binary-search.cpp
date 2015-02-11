// Herman Zvonimir Došilović
/*
Binarno pretrazivanje koje pretrazuje polje od N elemenata.
Trazi se element vrijednosti k. Ako takav element ne postoji vratiti -1.
*/
#include <cstdio>

int p[1000];

int binary_search(int *p, int n, int k)
{
    int hi = n - 1, lo = 0, mid;
    while(lo <= hi)
    {
        mid = lo + (hi - lo)/2;
        if(p[mid] == k)
            return mid;
        else if(p[mid] > k)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

int main()
{
    int N, k;
    scanf("%d%d", &N, &k);
    for(int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    int index = binary_search(p, N, k);
    printf("%d\n", index);
    return 0;
}
