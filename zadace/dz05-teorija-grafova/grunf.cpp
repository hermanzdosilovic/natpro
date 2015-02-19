// Ivan Krpelnik
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 300

int n, m;
float dp[MAXN+1][MAXN+1];
float c;

float mini(float a, float b) {
    if(a == -1)
        return b;
    return a < b ? a : b;
}

int main()
{
    scanf("%d %d", &n, &m);
    int i, j, k;
    for(i = 1; i <= n; ++i) {
        dp[i][i] = 1;
        for(j = i+1; j <= n; ++j)
            dp[i][j] = dp[j][i] = -1;
    }

    for(i = 0; i < m; ++i) {
        scanf("%d %d %f", &j, &k, &c);
        dp[j][k] = mini(dp[j][k], c);
    }
    for(k = 1; k <= n; ++k)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                if(dp[i][k] != -1 && dp[k][j] != -1)
                    dp[i][j] = mini(dp[i][j], dp[i][k] * dp[k][j]);
    if(dp[1][n] == -1)
        printf("nemoguce\n");
    else {
        bool neg = 0;
        for(k = 1; k <= n; ++k)
            if(dp[1][k] != -1 && dp[k][n] != -1 && dp[k][k] < 1)
                neg = 1;
        if(neg) {
            printf("tezi 0\n");
        } else {
            printf("%.6f\n", dp[1][n]);
        }
    }
    return 0;
}
