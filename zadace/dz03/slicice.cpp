#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000000;
int N, A, B;

int memo[MAXN + 3][2];

int f(int N, int P) {
  if (memo[N][P] != -1)
    return memo[N][P];
  if (memo[N][!P] != -1)
    return !memo[N][!P];
  int c1 = -1, c2 = -1, c3 = -1;
  if (N >= A)
    c1 = f(N - A, !P);
  if (N >= B)
    c2 = f(N - B, !P);
  c3 = f(N - 1, !P);

  if (c1 == P || c2 == P || c3 == P) {
    memo[N][P] = P;
    memo[N][!P] = !P;
  }
  else {
    memo[N][P] = !P;
    memo[N][!P] = P;
  }

  return memo[N][P];
}

int main() {
  int M;
  scanf("%d%d%d", &M, &A, &B);
  memset(memo, -1, sizeof(memo));
  memo[0][0] = 1;
  memo[0][1] = 0;
  while (M--) {
    scanf("%d", &N);

    int c = f(N, 1);
    if (memo[N][1])
      printf("mirko\n");
    else
      printf("slavko\n");
  }
  return 0;
}
