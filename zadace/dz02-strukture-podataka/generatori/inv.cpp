#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

set<int> s;
int main() {
  srand(time(0));
  int N, MAXA;
  scanf("%d%d", &N, &MAXA);
  printf("%d\n", N);
  while (s.size() < N) {
    int k = rand()%MAXA + 1;
    if(s.insert(k).second == true) {
      printf("%d", k);
      if (s.size() < N)
        printf(" ");
    }
  }
  printf("\n");
}
