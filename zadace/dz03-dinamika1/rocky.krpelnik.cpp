#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 1000007

int n;
int dp[1000006];

int main()
{
    scanf("%d", &n);
    dp[0] = 1;
    int i;
    for(i = 0; i < n; ++i) {
        dp[i+1] = (dp[i+1] + dp[i]) % MOD;
        dp[i+2] = (dp[i+2] + dp[i]) % MOD;
        dp[i+3] = (dp[i+3] + dp[i]) % MOD;
    }
    printf("%d\n", dp[n]);
    return 0;
}
