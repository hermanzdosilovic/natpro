#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 50;
const int BIGN = 100000;

int N, M;
int n[MAXN + 3], z[BIGN + 3];
set<int> prosti;

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", n + i);
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
      for (int i = 0; i < N; i++) {
        if(cnt < M && n[i]%br == 0) {
          cnt++;
          n[i] /= br;
          z[br]--;
        }
      }
      sort(n, n + N);
      reverse(n, n + N);
    }
  }

  printf("%lld\n", sol);

  return 0;
}
