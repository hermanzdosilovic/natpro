#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N;
char p[MAXN + 4][MAXN + 4];
int f[MAXN + 4][MAXN + 4];

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf(" %c", &p[i][j]);
      p[i][j] -= '0';
    }
  }

  int sol = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (!p[i][j]) {
        f[i][j] = 1 + min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1]));
        sol = max(sol, f[i][j]);
      }
    }
  }

  printf("%d\n", sol);
  return 0;
}
