#include <cstdio>
#include <cstring>

typedef long long lld;

const lld B = 17;
const lld MOD = 1000003;
const int MAXLEN = 100000;

char pattern[MAXLEN + 1], str[MAXLEN + 1];
lld b[MAXLEN + 1];

int main() {
  scanf(" %s %s", pattern, str);
  b[0] = 1;
  int h_pattern = pattern[0];

  int len = strlen(pattern);
  for (int i = 1; i < len; i++) {
    h_pattern *= B;
    h_pattern += pattern[i];
    h_pattern %= MOD;
    b[i] = b[i - 1]*B;
  }


  int h_n = str[0];
  for (int i = 1; i < len; i++) {
    h_n *= B;
    h_n += str[i];
    h_n %= MOD;
  }

  if (h_n == h_pattern) {
    printf("Yes 0\n");
  }

  for (int i = 1; str[i+len-1]; i++) {
    h_n = (h_n - str[i-1]*b[len - 1])*B + str[i+len-1];
    h_n %= MOD;
    if (h_n == h_pattern) {
      printf("Yes %d\n", i);
    }
  }

  return 0;
}
