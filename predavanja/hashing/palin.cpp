#include <cstdio>
#include <cstring>

typedef long long lld;

const lld B = 17;
const lld MOD = 1000003;
const int MAXLEN = 10000;

char s[MAXLEN + 1];
lld b[MAXLEN + 1];
int hleft[MAXLEN + 1];
int hright[MAXLEN + 1];

int hash_left(int x, int y) {
  return ((hleft[y] - hleft[x - 1]*b[y - x + 1])%MOD + MOD)%MOD;
}

int hash_right(int x, int y) {
  return ((hright[y] - hright[x - 1]*b[y - x + 1]%MOD) + MOD)%MOD;
}

int main() {
  scanf("%[^\n]", s);

  int len = strlen(s);
  b[0] = 1;
  hleft[0] = s[0];
  hright[0] = s[len - 1];

  for (int i = 1; i < len; i++) {
    hleft[i] = (hleft[i - 1]*B + s[i])%MOD;
    hright[i] = (hright[i - 1]*B + s[len - 1 - i])%MOD;
    b[i] = b[i - 1]*B;
  }

  int x, y;
  scanf("%d%d", &x, &y);
  if (hash_left(x, y) == hash_right(len - 1 - y, len - 1 - x))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
