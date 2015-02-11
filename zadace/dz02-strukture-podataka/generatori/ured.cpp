#include <cstdio>
#include <ctime>
#include <cstdlib>

int main() {
  int N, K, Q;
  long long T;
  scanf("%d%d%lld", &N, &K, &T);
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    printf("%lld", (rand()%T + T)%T);
    if (i != N - 1)
      printf(" ");
  }
  printf("\n%d\n", K);
  for (int i = 0; i < K; i++) {
    if (rand()%2) {
      int a = rand()%N + 1;
      printf("sef %d %d\n", a, a + rand()%(N + 1 - a));
    } else {
      printf("promjena %d %lld\n", rand()%N + 1, (rand()%T + T)%T);
    }
  }
  printf("\n");
  return 0;
}
