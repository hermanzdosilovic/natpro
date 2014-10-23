#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long lld;
typedef pair<lld, lld> llp;

const lld INF = 0x7fffffffffffffff;
const int MAXL = 100000;

llp tree[1 << 18];
bool enable[MAXL + 3];
int I, L;
lld R, K;
char c[6];

void update(int n, int l, int r) {
  if (r < I || l > I) {
    return;
  } else if (l == r && r == I) {
    tree[n] = mp(K, K);
    if(!enable[I]) {
      tree[n] = mp(0, INF);
    }
    return;
  } else if (l == r) {
    return;
  }
  update(2*n, l, (l+r)/2);
  update(2*n + 1, (l+r)/2 + 1, r);
  tree[n].x = max(tree[2*n].x, tree[2*n + 1].x);
  tree[n].y = min(tree[2*n].y, tree[2*n + 1].y);
}

llp query(int n, int l, int r) {
  if (l > I) {
    return mp(0, INF);
  }
  else if (l >= 1 && r <= I) {
    return tree[n];
  }
  llp q = query(2*n, l, (l+r)/2);
  llp p = query(2*n + 1, (l+r)/2 + 1, r);
  return mp(max(q.x, p.x), min(q.y, p.y));
}

void init(int n, int l, int r) {
  tree[n] = mp(0, INF);
  if(l == r) {
    return;
  }
  init(2*n, l, (l+r)/2);
  init(2*n + 1, (l+r)/2 + 1, r);
}

int main() {
  scanf("%d", &L);
  init(1, 1, L - 1);
  while (1) {
    scanf("%s", c);
    if (c[0] == 'A') {
      scanf("%d%lld", &I, &K);
      I++;
      enable[I] = true;
      update(1, 1, L - 1);
    } else if (c[0] == 'D') {
      scanf("%d", &I);
      I++;
      enable[I] = false;
      K = 0;
      update(1, 1, L - 1);
    } else if (c[0] == 'Q') {
      scanf("%lld", &R);
      int sol = 0;
      lld najveca = 0;
      for (int i = 0; i < L; i++) {
        I = i + 1;
        if (!enable[I])
          continue;
        llp n = query(1, 1, L - 1);
        lld trenutna = (n.x - n.y)*i;
        if(trenutna <= R && trenutna >= najveca) {
          najveca = trenutna;
          sol = i;
        }
      }
      printf("%d\n", sol);
    } else {
      break;
    }
  }
  return 0;
}
