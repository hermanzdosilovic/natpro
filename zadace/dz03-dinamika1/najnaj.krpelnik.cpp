#include <iostream>
#include <cstdio>

using namespace std;

int n;
char mat[1003][1003];
int dp[1003][1003];
int sol;

int main()
{
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; ++i)
        scanf("%s", mat[i]);
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j) {
            if(mat[i][j] == '1')
                continue;
            dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
            sol = max(sol, dp[i+1][j+1]);
        }
    printf("%d\n", sol);
    return 0;
}
