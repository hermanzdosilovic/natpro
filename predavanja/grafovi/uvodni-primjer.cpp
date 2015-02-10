#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

#define MAXN 1000

char polje[MAXN][MAXN + 1];
bool bio[MAXN][MAXN];
int dist[MAXN][MAXN];
int n, m;

struct par {
  int x, y;
  par() {}
  par (int _x, int _y): x(_x), y(_y) {}
  bool ok() {
    return x >= 0 && y >= && x < n && y < m && !bio[x][y] polje[x][y] != '#';
  }
};

par p, k;

par delta[] = {par(0, 1), par(1, 0), par(0, -1), par(-1, 0)};

par operator +(const par &a, const par &b) {
  return par(a.x + b.x, a.y + b.y);
}

void bfs() {
  queue<par> q;
  q.push(p);
  dist[p.x][p.y] = 0;
  bio[p.x][p.y] = 1;
  while(!q.empty()) {
    par vrh = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      par sus = vrh + delta[i];
      if (sus.ok()) {
        q.push(sus);
        dist[sus.x][sus.y] = dist[vrh.x][vrh.y] + 1;
        bio[sus.x][sus.y] = 1;
      }
    }
  }
}

