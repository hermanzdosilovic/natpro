#include <stdio.h>

int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);

    int sol = 1, n5 = 0;
    for (int i = 2; i <= N; i++) {
      if (i%5 == 0) {
        int k = i;
        while (k%5 == 0) {
          n5++;
          k /= 5;
        }
      }
    }

    for (int i = 2; i <= N; i++) {
      int k = i;
      while (k%5 == 0) {
        k /= 5;
      }
      while (k%2 == 0 && n5) {
        k /= 2;
        n5--;
      }
      sol *= k;
      sol %= 10;
    }

    printf("%d\n", sol);
  }

  return 0;
}
