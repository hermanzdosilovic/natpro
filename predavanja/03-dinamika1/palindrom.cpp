// Ivan Krpelnik
#include <iostream>
#include <cstdio>
#include <cstring>

char s[1003];
int dp[1003][1003];

bool palindrom(int l, int r)
{
    for(int i = l, j = 0; i <= r; ++i, ++j)
        if(s[i] != s[r-j])
            return 0;
    return 1;
}

int f(int l, int r)
{
    if(dp[l][r] || palindrom(l, r))
        return dp[l][r] = 1;
    if(dp[l][r])
        return dp[l][r];
    int sol = 1 << 30;
    for(int i = l; i < r; ++i)
        sol = std::min(sol, f(l, i) + f(i+1, r));
    return dp[l][r] = sol;
}


int main()
{
    scanf("%s", s);
    printf("%d\n", f(0, strlen(s)-1));
    return 0;
}
