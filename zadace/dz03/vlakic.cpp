#include <cstdio>
#include <cstring>

typedef long long lld;

const int MOD = 1440;
const int MAXN = 20;

lld memo[MAXN + 2][MAXN + 2][MAXN + 2];

lld f(lld R, lld G, lld B) {
  if (memo[R][G][B] != -1)
    return memo[R][G][B];
  lld sol = 0;
  if (R > 0) {
    sol += f(R - 1, G, B)%MOD;
  }
  if (G > 0) {
    sol += f(R, G - 1, B)%MOD;
  }
  if (B > 0) {
    sol += f(R, G, B - 1)%MOD;
  }
  return memo[R][G][B] = sol%MOD;
}

int main() {
  lld R, G, B;
  scanf("%lld%lld%lld", &R, &G, &B);
  memset(memo, -1, sizeof(memo));
  memo[0][0][0] = memo[0][0][1] = memo[0][1][0] = memo[1][0][0] = 1;
  memo[0][1][1] = memo[1][0][1] = memo[1][1][0] = 2;
  memo[1][1][1] = 6;
  lld sol = f(R - 1, G, B)%MOD + f(R, G - 1, B)%MOD + f(R, G, B - 1)%MOD + 720;
  sol %= MOD;
  char out[] = "00:00";
  int hh = sol/60;
  int mm = sol - hh*60;
  out[0] = hh/10 + '0';
  out[1] = hh%10 + '0';
  out[3] = mm/10 + '0';
  out[4] = mm%10 + '0';
  printf("%s\n", out);
  return 0;
}
