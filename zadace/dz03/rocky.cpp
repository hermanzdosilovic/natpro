#include <cstdio>
#include <cstring>

const int MOD = 1000007;
const int MAXN = 1000000;

int memo[MAXN + 3];

int f(int N) {
  if (memo[N] != -1)
    return memo[N];
  memo[N] = (f(N - 1)%MOD + f(N - 2)%MOD + f(N - 3)%MOD)%MOD;
  return memo[N];
}

int main() {
  int N;
  scanf("%d", &N);
  memset(memo, -1, sizeof(memo));
  memo[0] = memo[1] = 1;
  memo[2] = 2;
  printf("%d\n", f(N));
  return 0;
}
