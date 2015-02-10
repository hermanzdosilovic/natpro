#include <cstdio>
#include <cmath>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

const int MAXLEN = 200000;
const int MAXN = 2000000;

int N, n[MAXLEN + 3], maxn;
int zastupljenost[MAXN + 3];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &n[i]);
    maxn = MAX(maxn, n[i]);
  }

  for (int i = 0; i < N; i++) {
    int root = sqrt(n[i]);
    for (int x = 1; x <= root; x++) {
      if (n[i]%x == 0) {
        zastupljenost[x]++;
        if (x != n[i]/x)
          zastupljenost[n[i]/x]++;
      }
    }
  }

  long long sol = 0;
  for (long long i = 1; i <= maxn; i++) {
    if (zastupljenost[i]*i >= sol && zastupljenost[i] >= 2)
      sol = zastupljenost[i]*i;
  }

  printf("%lld\n", sol);

  return 0;
}
