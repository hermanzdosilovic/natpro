#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define mp make_pair

using namespace std;
const int N = 1000;

char bomba[2*N+3][N+3];
int bod[2*N+3][N+3];
int memo[2*N+3][N+3];
int pr[2*N+3][N+3];
int digit[2*N+3][N+3];
int max_t;

int f(int x, int t) {

  int &ref = memo[x + N][t];

  if(ref != -1)
    return ref;
  if(t == max_t)
    return bod[x + N][t];
  if(bomba[x + N][t])
    return 0;

  ref = bod[x + N][t];

  int a = f(x - 1, t + 1);
  int b = f(x, t + 1);
  int c = f(x + 1, t + 1);
  if (a >= b && a >= c && a != 0) {
    ref += a;
    pr[x + N][t] = x - 1;
    digit[x + N][t] = 4;
  }
  else if (b >= a && b >= c && b != 0) {
    ref += b;
    pr[x + N][t] = x;
    digit[x + N][t] = 5;
  }
  else if (c != 0) {
    ref += c;
    pr[x + N][t] = x + 1;
    digit[x + N][t] = 6;
  }


  return ref;
}

void reconstruct(int x, int t) {
  if (pr[x + N][t] > 10000)
    return;
  printf("%d", digit[x + N][t]);
  reconstruct(pr[x + N][t], t + 1);
}

int main() {

  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    char s[23];
    int x, t, b;
    scanf("%s", s);
    if(!strcmp(s, "bomba")) {
      scanf("%d%d", &x, &t);
      bomba[x + N][t] = '1';
    }
    else {
      scanf("%d%d%d", &x, &t, &b);
      bod[x + N][t] = b;
    }

    max_t = max(t, max_t);
  }

  vector<int> *sol;

  memset(memo, -1, sizeof(memo));
  memset(pr, 63, sizeof(pr));
  printf("%d\n", f(0, 0));
  reconstruct(0, 0);
  return 0;
}
