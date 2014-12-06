#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;


char p[MAX + 3][MAX + 3];
bool bio[MAX + 3][MAX + 3];
int dist[MAX + 3][MAX + 3];
int N, M;

struct par {
  int x, y;
  par() {}
  par (int _x, int _y): x(_x), y(_y) {}
  bool ok() {
    return x >= 0 && y >= 0 && x < N && y < M && !bio[x][y] && p[x][y] != '*';
  }
};

par d[] = {par(1, 0), par(0, 1), par(-1, 0), par(0, -1)};

par operator +(const par &a, const par &b) {
  return par(a.x + b.x, a.y + b.y);
}

queue<par> q;

int main() {
  int T;
  par start, finish;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf(" %c", &p[i][j]);
        if (p[i][j] == '$')
          start = par(i, j);
        if (p[i][j] == '#')
          finish = par(i, j);
      }
    }

    memset(bio, 0, sizeof(bio));
    memset(dist, 0, sizeof(dist));
    dist[finish.x][finish.y] = -1;
    q.push(start);
    bio[start.x][start.y] = 1;
    while(!q.empty()) {
      par vrh = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        par sus = vrh + d[i];
        if (sus.ok()) {
          q.push(sus);
          bio[sus.x][sus.y] = 1;
          dist[sus.x][sus.y] = dist[vrh.x][vrh.y] + 1;
        }
      }
    }

    printf("%d\n", dist[finish.x][finish.y]);
  }
  return 0;
}
