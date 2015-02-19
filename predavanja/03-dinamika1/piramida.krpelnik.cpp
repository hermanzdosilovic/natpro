#include <iostream>
#include <cstdio>

#define oo 1<<30

using namespace std;

int dp[1005][1005];
int n, m;
int mat[1005][1005];

int main()
{
    scanf("%d", &n);
    int i, j;
    for(i = 0; i <= n+1; ++i)
        dp[i][0] = dp[i][n+1] = -oo;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j) {
            scanf("%d", &mat[i][j]);
            dp[i][j] = mat[i][j];
        }
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) + mat[i][j];
    int sol = -oo;
    for(i = 1; i <= n; ++i)
        sol = max(sol, dp[n][i]);
    printf("%d\n", sol);
    return 0;
}
