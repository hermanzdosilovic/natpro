#include <iostream>
#include <cstdio>

using namespace std;

int n, x;
int t[1003], v[1003];
int dp[2][1003];

int main()
{
    scanf("%d %d", &x, &n);
    int i, j;
    bool b = 0;
    for(i = 0; i < n; ++i)
        scanf("%d %d", &t[i], &v[i]);
    for(i = 1; i <= n; ++i, b = !b)
        for(j = 0; j <= x; ++j) {
            dp[b][j] = dp[!b][j];
            if(j >= t[i])
                dp[b][j] = max(dp[b][j], dp[!b][j - t[i]] + v[i]);
        }
    printf("%d\n", dp[!b][x]);
    return 0;
}
