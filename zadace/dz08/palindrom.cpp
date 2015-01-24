#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXLEN = 100000;
const llint B = 31;
const llint MOD = 1000000007;

int length;
char word[MAXLEN + 3];
llint base[MAXLEN + 3];
llint lh[MAXLEN + 3], rh[MAXLEN + 3];

llint lhash(int a, int b) {
  return ((lh[b] - base[b - a + 1]*lh[a - 1])%MOD + MOD)%MOD;
}

llint rhash(int a, int b) {
  return ((rh[a] - base[b - a + 1]*rh[b + 1])%MOD + MOD)%MOD;
}

int main() {
  scanf("%d%s", &length, word);

  base[0] = 1;
  lh[0] = word[0];
  rh[length - 1] = word[length - 1];

  for (int i = 1; i < length; i++) {
    lh[i] = (B*lh[i - 1] + word[i])%MOD;
    rh[length - 1 - i] = (B*rh[length - i] + word[length - 1 - i])%MOD;
    base[i] = B*base[i - 1];
  }

  int maxlen = 1;
  for (int k = 0; k < length; k++) {
    int lo = 0, hi = min(k, length - 1 - k), mid;
    while (lo < hi) {
      mid = (hi + lo + 1)/2;
      if (lhash(k - mid, k) == rhash(k, k + mid))
        lo = mid;
      else
        hi = mid - 1;
    }
    maxlen = max(maxlen, 1 + 2*lo);
  }

  for (int k = 0; k < length - 1; k++) {
    if (word[k] != word[k + 1])
      continue;

    int lo = 0, hi = min(k, length - 2 - k), mid;
    while (lo < hi) {
      mid = (hi + lo + 1)/2;
      if (lhash(k - mid, k) == rhash(k + 1, k + 1 + mid))
        lo = mid;
      else
        hi = mid - 1;
    }
    maxlen = max(maxlen, 2*lo + 2);
  }

  printf("%d\n", maxlen);

  return 0;
}
