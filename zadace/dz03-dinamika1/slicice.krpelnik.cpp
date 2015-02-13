#include <iostream>
#include <cstdio>

using namespace std;

int n, a, b;
int dp[1000003];
char sol[2][10] = {"slavko", "mirko"};

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    dp[1] = dp[a] = dp[b] = dp[0] = 1;
    int i;
    for(i = 2; i <= 1000000; ++i) {
        if(i == a || i == b)
            continue;
        dp[i] = !dp[i-1];
        if(i >= a)
            dp[i] |= !dp[i-a];
        if(i >= b)
            dp[i] |= !dp[i-b];
    }
    for(i = 0; i < n; ++i) {
        scanf("%d", &a);
        printf("%s\n", sol[dp[a]]);
    }
    return 0;
}
