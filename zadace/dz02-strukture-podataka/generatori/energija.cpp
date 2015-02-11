#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <unistd.h>

using namespace std;

int L, Q;
int MAX_K;
long long MAX_R;

set<int> s;

int add() {
  int i = rand()%L;
  if (s.insert(i).second) {
    printf("ADD %d %d\n", i, rand()%MAX_K + 1);
    return 1;
  }
  return 0;
}

int del() {
  int i = rand()%L;
  if (s.erase(i)) {
    printf("DEL %d\n", i);
    return 1;
  }
  return 0;
}

int query() {
  printf("QUERY %lld\n", (rand()%MAX_R + MAX_R)%MAX_R);
  return 1;
}

int main() {
  srand(time(0));
  scanf("%d%d%d%lld", &L, &Q, &MAX_K, &MAX_R);
  printf("%d\n", L);
  for (int i = 0; i < Q; ) {
    if (i >= 0 && i <= Q/4) {
      if (add())
        i++;
    } else if (i > Q/4 && i <= Q/2) {
      if (i%2 && query())
        i++;
      else if (del())
        i++;
    } else {
      if (rand()%3 == 0 && query())
        i++;
      else if (rand()%3 == 1 && add())
        i++;
      else if (del())
        i++;
    }
  }
  printf("EXIT\n");
  return 0;
}
