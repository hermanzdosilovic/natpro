#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#define MAX 1000

using namespace std;

// O((N + M)logN)
struct Edge {
  int b, w;
  Edge () {};
  Edge (int b, int w): b(b), w(w) {}
};

vector<Edge> g[MAX];
int d[MAX]; // trenutne procjene za udaljenost
int N, M;

struct cmp {
  bool operator ()(int a, int b) {
    if(d[a] == d[b])
      return a < b;
    return d[a] < d[b];
  }
};

set<int, cmp> pq;

void dijkstra(int src) { // pocetni cvor od kojeg racunamo udaljenosti
  memset(d, 0x3f, sizeof(d));
  pq.insert(src);
  d[src] = 0;
  while(!pq.empty()) {
    int now = *pq.begin();
    pq.erase(now);
    for (int i = 0; i < (int) g[now].size(); i++) {
      int sus = g[now][i].b;
      int w = g[now][i].w;
      if (d[sus] > d[now] + w) {
        pq.erase(sus);
        d[sus] = d[now] + w;
        pq.insert(sus);
      }
    }
  }
}

int main() {
 return 0;
}
