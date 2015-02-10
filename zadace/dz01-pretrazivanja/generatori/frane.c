#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  srand(time(0));
  int N, MAXX;
  scanf("%d %d", &N, &MAXX);
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    printf("%d", rand()%MAXX + 1);
    if (i != N - 1)
      printf(" ");
  }
  printf("\n");
  return 0;
}
