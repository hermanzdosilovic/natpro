#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long lld;

const int MAXN = 100000;
const lld INF = 0x7fffffffffffffff;

int N, K, A, B;
char c[9];
lld tree[1 << 18], w[MAXN + 3], T;

void init(int n, int l, int r) {
  if (l == r) {
    tree[n] = w[l];
    return;
  }
  init(2*n, l, (l+r)/2);
  init(2*n + 1, (l+r)/2 + 1, r);
  tree[n] = min(tree[2*n], tree[2*n + 1]);
}

lld query(int n, int l, int r) {
  if (l > B || r < A) {
    return INF;
  } else if (l >= A && r <= B) {
    return tree[n];
  }
  lld q = query(2*n, l, (l+r)/2);
  lld p = query(2*n + 1, (l+r)/2 + 1, r);
  return min(q, p);
}

void update(int n, int l, int r) {
  if (l > A || r < A) {
    return;
  } else if (l == r && r == A) {
    tree[n] = w[A];
    return;
  } else if (l == r) {
    return;
  }
  update(2*n, l, (l+r)/2);
  update(2*n + 1, (l+r)/2 + 1, r);
  tree[n] = min(tree[2*n], tree[2*n + 1]);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &w[i]);
  }
  init(1, 1, N);
  scanf("%d", &K);
  while (K--) {
    scanf("%s", c);
    if (c[0] == 's') {
      scanf("%d%d", &A, &B);
      printf("%lld\n", query(1, 1, N));
    } else {
      scanf("%d%lld", &A, &T);
      w[A] = T;
      update(1, 1, N);
    }
  }
  return 0;
}
