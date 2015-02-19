// Ivan Krpelnik
#include <cstdio>
#include <iostream>
#include <vector>

#define MAXN 100000
#define MAXM 200000

using namespace std;

int n, m;
vector<int> v[MAXN];
bool bio[MAXN];
int sol;

void dfs(int x) {
    bio[x] = 1;
    int d = v[x].size();
    for(int i = 0; i < d; ++i)
        if(!bio[v[x][i]])
            dfs(v[x][i]);
}

int main()
{
    scanf("%d %d", &n, &m);
    int x, y;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < n; ++i) {
        if(!bio[i]) {
            sol++;
            dfs(i);
        }
    }
    printf("%d\n", sol);
    return 0;
}
