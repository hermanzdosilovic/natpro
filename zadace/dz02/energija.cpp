#include <cstdio>
#include <algorithm>
#include <set>
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long lld;
typedef pair<lld, lld> llp;

const lld INF = 0x7fffffffffffffff;
const int MAXL = 100000;

set<lld> s;
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
  init(1, 1, L);
  while (1) {
    scanf("%s", c);
    if (c[0] == 'A') {
      scanf("%d%lld", &I, &K);
      I++;
      enable[I] = true;
      s.insert(I);
      update(1, 1, L);
    } else if (c[0] == 'D') {
      scanf("%d", &I);
      I++;
      enable[I] = false;
      s.erase(I);
      K = 0;
      update(1, 1, L);
    } else if (c[0] == 'Q') {
      scanf("%lld", &R);
      int sol = 0;
      int lo = 1, mid, hi = L;
      if(s.empty()) {
        printf("%d\n", sol);
        continue;
      }
      while (lo < hi) {
        mid = lo + (hi - lo)/2 + 1;
        I = mid;
        llp n = query(1, 1, L);
        lld trenutna = (n.x - n.y)*(mid - 1);
        if(trenutna > R)
          hi = mid - 1;
        else
          lo = mid;
      }
      if(enable[lo]) {
        sol = lo - 1;
      } else {
        set<lld>::iterator i = s.lower_bound(lo);
        sol = *i - 1;
        if(*i != lo) {
          sol = *--i - 1;
        }
      }
      printf("%d\n", sol);
    } else {
      break;
    }
  }
  return 0;
}
