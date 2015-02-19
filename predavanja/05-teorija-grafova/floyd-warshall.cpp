// Ivan Krpelnik
#include <iostream>
#include <cstdio>

#define MAXN 100

int dp[MAXN][MAXN];

int main()
{
    int i, j, k;
    for(k = 0; k < n; ++k)
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    return 0;
}