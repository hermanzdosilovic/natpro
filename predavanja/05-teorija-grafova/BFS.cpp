// Ivan Krpelnik
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

#define MAXN 100

using namespace std;

int t;
char polje[MAXN][MAXN+1];
bool bio[MAXN][MAXN+1];
int dist[MAXN][MAXN];
int n, m;

struct par {
    int x, y;
    par() {}
    par(int x, int y): x(x), y(y) {}
    bool ok() {
        return x >= 0 && y >= 0 && x < n && y < m && !bio[x][y] && polje[x][y] != '*';
    }
};

par p, k;
par delta[] = {par(0, 1), par(1, 0), par(0, -1), par(-1, 0)};

par operator +(const par &a, const par &b) {
    return par(a.x + b.x, a.y + b.y);
}

void bfs() {
    memset(bio, 0, sizeof bio);
    memset(dist, 0, sizeof dist);
    queue<par> q;
    q.push(p);
    dist[p.x][p.y] = 0;
    bio[p.x][p.y] = 1;
    while(!q.empty()) {
        par pos = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            par sused = pos + delta[i];
            if(sused.ok()) {
                q.push(sused);
                bio[sused.x][sused.y] = 1;
                dist[sused.x][sused.y] = dist[pos.x][pos.y] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%s", polje[i]);
            for(int j = 0; j < m; ++j) {
                if(polje[i][j] == '$') {
                    p = par(i, j);
                } else if(polje[i][j] == '#') {
                    k = par(i, j);
                }
            }
        }
        bfs();
        printf("%d\n", bio[k.x][k.y] ? dist[k.x][k.y] : -1);
    }
    return 0;
}
