// Herman Zvonimir Došilović
// http://www.spoj.com/problems/CCOMPS/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100000;

vector<int> ls[MAXN + 1];
queue<int> q;
bool bio[MAXN + 1];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ls[a].push_back(b);
    ls[b].push_back(a);
  }
  int sol = 0;
  for (int i = 1; i <= N; i++) {
    if (!bio[i]) {
      sol++;
      q.push(i);
      while(!q.empty()) {
        int v = q.front();
        q.pop();
        int s = ls[v].size();
        for (int k = 0; k < s; k++) {
          if (!bio[ls[v][k]]) {
            q.push(ls[v][k]);
            bio[ls[v][k]] = 1;
          }
        }
      }
    }
  }
  printf("%d\n", sol);
  return 0;
}
