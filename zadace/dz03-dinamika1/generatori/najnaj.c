#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  srand(time(0));
  int N;
  scanf("%d", &N);
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", rand()%2 && (i*rand()%7)%2 && (j*13337)%2);
    }
    printf("\n");
  }
  return 0;
}
