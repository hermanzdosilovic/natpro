#include <cstdio>
#include <cstring>

const int MOD = 1000007;
const int MAXN = 1000000;

int dp[MAXN + 3];
int main() {
  int N;
  scanf("%d", &N);
  dp[0] = dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= N; i++) {
    dp[i] = dp[i - 1]%MOD + dp[i - 2]%MOD + dp[i - 3]%MOD;
    dp[i] %= MOD;
  }
  printf("%d\n", dp[N]);
  return 0;
}
