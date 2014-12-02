#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 50;
const int BIGN = 1000000000;

int N, M;
int n[MAXN + 3];
set<int> prosti;
map<int, int> z;
int prime_br;

bool cmp(int x, int y) {
  int xcnt = 0;
  while(x%prime_br == 0) {
    x /= prime_br;
    xcnt++;
  }

  int ycnt = 0;
  while(y%prime_br == 0) {
    y /= prime_br;
    ycnt++;
  }

  if (xcnt > ycnt)
    return true;
  return false;
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &n[i]);
  }

  scanf("%d", &M);

  for (int i = 0; i < N; i++) {
    int root = sqrt(n[i]);
    int m = n[i];

    for (int k = 2; k <= root; k++) {
      if (m%k == 0) {
        prosti.insert(k);
        while (m%k == 0) {
          z[k]++;
          m /= k;
        }
      }
    }

    if (m != 1) {
      z[m]++;
      prosti.insert(m);
    }
  }

  long long sol = 0;
  for(set<int>::iterator p = prosti.begin(); p != prosti.end(); p++) {
    int br = *p;
    sol++;
    while (z[br]) {
      sol++;
      int cnt = 0;
      prime_br = br;
      sort(n, n + N, cmp);
      for (int i = 0; i < N; i++) {
        if(cnt < M && n[i]%br == 0) {
          cnt++;
          n[i] /= br;
          z[br]--;
        }
      }
    }
  }

  printf("%lld\n", sol);

  return 0;
}
