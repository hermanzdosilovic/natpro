#include <cstdio>
#include <queue>
#define x first
#define y second

#define MAXR 250
#define MAXS 250

using namespace std;

typedef pair<int, int> pii;
char p[MAXR + 1][MAXS + 1];
queue<pii> q;
bool bio[MAXR + 1][MAXS + 1];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int R, S;

int ok(int x, int y) {
  return x >= 0 && y >= 0 && x < R && y < S && !bio[x][y] && p[x][y] != '#';
}

int main() {
  scanf("%d%d", &R, &S);
  for (int i = 0; i < R; i++)
    scanf("%s", p[i]);

  int prezivjeli_vukovi = 0;
  int prezivjele_koze = 0;
  for (int x = 0; x < R; x++) {
    for (int y = 0; y < S; y++) {
      if (p[x][y] != '#' && !bio[x][y]) {
        bio[x][y] = 1;
        q.push(make_pair(x, y));
        int vukovi = 0;
        int koze = 0;
        while(!q.empty()) {
          pii v = q.front();
          q.pop();
          if (p[v.x][v.y] == 'k')
            koze++;
          if (p[v.x][v.y] == 'v')
            vukovi++;
          for (int i = 0; i < 4; i++) {
            if (ok(v.x + dx[i], v.y + dy[i])) {
              bio[v.x + dx[i]][v.y + dy[i]] = 1;
              q.push(make_pair(v.x + dx[i], v.y + dy[i]));
            }
          }
        }
        if (koze > vukovi)
          prezivjele_koze += koze;
        else
          prezivjeli_vukovi += vukovi;
      }
    }
  }
  printf("%d %d\n", prezivjele_koze, prezivjeli_vukovi);
  return 0;
}
