// Ivan Krpelnik
#include <iostream>
#include <cstdio>

int n, m;
char mat[1003][1003];
int dp[1003][1003];

int main()
{
    scanf("%d %d", &n, &m);
    int i, j;
    for(i = 0; i < n; ++i)
        scanf("%s", mat[i]);
    dp[0][0] = 1;
    for(i = 1; i < m; ++i) {
        if(dp[0][i-1] == 0)
            break;
        dp[0][i] = 1;
    }
    for(i = 1; i < n; ++i)
        for(j = 0; j < m; ++j) {
            if(mat[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j > 0)
                dp[i][j] += dp[i-1][j-1];
        }
    printf("%d\n", dp[n-1][m-1]);
    return 0;
}
