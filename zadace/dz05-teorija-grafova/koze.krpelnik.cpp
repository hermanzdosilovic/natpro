#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 250

int R, S;
char s[MAXN][MAXN+1];
int v, k;
int solv, solk;
bool bio[MAXN][MAXN];

struct point {
    point() {}
    point(int x, int y): x(x), y(y) {}

    bool ok() {
        return x >= 0 && x < R && y >= 0 && y < S && s[x][y] != '#' && !bio[x][y];
    }

    int x, y;
};

point operator+ (const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
}

point d[] = {point(0, 1), point(1, 0), point(0, -1), point(-1, 0)};

void dfs(point p) {
    bio[p.x][p.y] = 1;
    v += s[p.x][p.y] == 'v';
    k += s[p.x][p.y] == 'k';
    for(int i = 0; i < 4; ++i) {
        point n = p + d[i];
        if(n.ok()) {
            dfs(n);
        }
    }
}

int main()
{
    scanf("%d %d", &R, &S);
    int i, j;
    for(i = 0; i < R; ++i)
        scanf("%s", s[i]);

    for(i = 0; i < R; ++i) {
        for(j = 0; j < S; ++j) {
            if(!bio[i][j] && s[i][j] != '#') {
                v = k = 0;
                dfs(point(i, j));
                if(k != 0 || v != 0)
                    if(k > v)
                        solk += k;
                    else
                        solv += v;
            }
        }
    }
    printf("%d %d\n", solk, solv);
    return 0;
}
