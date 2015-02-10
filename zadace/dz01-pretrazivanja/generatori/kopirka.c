#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(0));
  int M, K, MAXP;
  scanf("%d %d", &M, &MAXP);
  K = rand()%M + 1;
  printf("%d %d\n", M, K);
  for (int i = 0; i < M; i++) {
    printf("%d", rand()%MAXP + 1);
    if (i != M - 1)
      printf(" ");
  }
  printf("\n");
  return 0;
}
