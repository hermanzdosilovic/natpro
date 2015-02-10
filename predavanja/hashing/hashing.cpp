#include <cstdio>
#include <cstring>

typedef long long lld;

const lld MAXLEN = 100000;
const lld MOD = 1000003;
const lld B = 17;

char s[MAXLEN + 1];
int h[MAXLEN + 1];
lld b[MAXLEN + 1];

int hash(int x, int y) {
  return ((h[y] - h[x - 1]*b[y - x + 1])%MOD + MOD)%MOD;
}

int main() {
  scanf("%[^\n]", s);
  h[0] = s[0]%MOD;
  b[0] = 1;

  int len = strlen(s);
  for (int i = 1; i < len; i++) {
    h[i] = (B*h[i-1] + s[i])%MOD;
    b[i] = b[i - 1]*B;
  }

  int a = 1, b = 1;
  while (a || b) {
    scanf("%d%d", &a, &b);
    printf("%d\n", hash(a, b));
  }

  return 0;
}
