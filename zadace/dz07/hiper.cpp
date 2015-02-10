#include <cstdio>
#include <algorithm>
#include <vector>

#define x first
#define y second
#define mp make_pair

using namespace std;

int N1, N2;
vector<pair<int, int> > v1;
vector<pair<int, int> > v2;

vector<pair<int, int> > w;

int main() {
  scanf("%d", &N1);
  for (int i = 0; i < N1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v1.push_back(mp(a, 1));
    v1.push_back(mp(a + b, 0));
  }
  scanf("%d", &N2);
  for (int i = 0; i < N2; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v2.push_back(mp(a, 1));
    v2.push_back(mp(a + b, 0));
  }

  sort(v1.begin(), v1.end());
  int cnt = 0;
  for (int i = 0; i < v1.size(); i++) {
    int s = v1[i].y;
    if (s == 1) {
      cnt++;
      if (cnt == 2)
        w.push_back(v1[i]);
    } else {
      cnt--;
      if (cnt == 1)
        w.push_back(v1[i]);
    }
  }

  sort(v2.begin(), v2.end());
  cnt = 0;
  for (int i = 0; i < v2.size(); i++) {
    int s = v2[i].y;
    if (s == 1) {
      cnt++;
      if (cnt == 2)
        w.push_back(v2[i]);
    } else {
      cnt--;
      if (cnt == 1)
        w.push_back(v2[i]);
    }
  }

  vector<pair<int, int> > p;
  sort(w.begin(), w.end());
  cnt = 0;
  for (int i = 0; i < w.size(); i++) {
    int s = w[i].y;
    if (s == 1) {
      cnt++;
      if (cnt == 2)
        p.push_back(w[i]);
    } else {
      cnt--;
      if (cnt == 1)
        p.push_back(w[i]);
    }
  }

  long long sol = 0;
  for (int i = 1; i < p.size(); i += 2) {
    sol += p[i].x - p[i - 1].x;
  }

  printf("%lld\n", sol);

  return 0;
}
