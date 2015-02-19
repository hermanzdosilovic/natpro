#include <iostream>
#include <cstdio>

using namespace std;

int n, x;
int t[1003], v[1003];
int dp[1003];

int main()
{
    scanf("%d %d", &n, &x);
    int i, j;
    for(i = 0; i < n; ++i)
        scanf("%d %d", &t[i], &v[i]);
    for(i = 0; i <= x; ++i)
        for(j = 0; j < n; ++j)
            if(t[j] >= i)
                dp[i] = max(dp[i], dp[i-t[j]] + v[j]);
    printf("%d\n", dp[x]);
    return 0;
}
