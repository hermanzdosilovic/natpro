#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 1440

int r, g, b;
int dp[63][23][23][23];
int sol;

int main()
{
    scanf("%d %d %d", &r, &g, &b);
    dp[r+g+b][r][g][b] = 1;
    int i, j, k, t;
    for(i = r+g+b-1; i >= 0; --i)
        for(j = 0; j <= r; ++j)
            for(k = 0; k <= g; ++k)
                for(t = 0; t <= b; ++t) {
                    dp[i][j][k][t] += dp[i+1][j+1][k][t] + dp[i+1][j][k+1][t] + dp[i+1][j][k][t+1];
                    dp[i][j][k][t] %= MOD;
                }
    sol = MOD / 2 + dp[0][0][0][0];
    sol %= MOD;
    printf("%0.2d:%0.2d\n", sol / 60, sol % 60);
    return 0;
}
