#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
const int INF = 1 << 31;

int N;
int a[MAXN + 3][MAXN + 3];
int f[MAXN + 3][MAXN + 3];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      f[i][j] = a[i][j] + max(f[i - 1][j], max(f[i - 1][j - 1], f[i - 1][j + 1]));
    }
  }
  int sol = INF;
  for (int i = 1; i <= N; i++) {
    sol = max(sol, f[N][i]);
  }
  printf("%d\n", sol);
  return 0;
}
