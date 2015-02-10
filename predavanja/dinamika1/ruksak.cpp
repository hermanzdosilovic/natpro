#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define mp make_pair

using namespace std;

const int MAXN = 10000;
const int MAXX = 10000;
int X, N;
pair<int, int> a[MAXN + 3];
int f[MAXX + 3];

int main() {
  scanf("%d%d", &X, &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  for (int x = 1; x <= X; x++) {
    for (int i = 0; i < N; i++) {
      if (a[i].x > x) {
        continue;
      }
      f[x] = max(a[i].y + f[x - a[i].x], f[x]);
    }
  }
  printf("%d\n", f[X]);
  return 0;
}
