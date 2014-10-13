#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int a[505];
vector<int> sol;

long long max(long long a, long long b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int M, K;
    long long lo = 0, hi = 0, mid;
    scanf("%d%d", &M, &K);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", a + i);
        hi += a[i];
        lo = max(lo, a[i]);
    }

    while(lo < hi)
    {
        mid = (hi + lo) / 2;
        long long sum = 0;
        int p = 1;
        for(int i = 0; i < M; i++)
        {
            if(sum + a[i] <= mid)
                sum += a[i];
            else
            {
                p++;
                sum = a[i];
            }
        }
        if(p <= K)
            hi = mid;
        else
            lo = mid + 1;
    }

    long long sum = 0;
    int p = K - 1;
    for(int i = M - 1; i >= 0; i--)
    {
        if(sum + a[i] > lo || i + 1 == p)
        {
            if(p != 0)
                sol.push_back(-1);
            p--;
            sum = 0;
        }
        sol.push_back(a[i]);
        sum += a[i];
    }
    reverse(sol.begin(), sol.end());
    int len = sol.size();
    for(int i = 0; i < len; i++)
        if(sol[i] == -1)
            printf("/ ");
        else {
            printf("%d", sol[i]);
            if(i != len - 1)
                printf(" ");
        }
    printf("\n");
    return 0;
}
