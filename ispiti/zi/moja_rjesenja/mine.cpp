#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int main() {
    int N, x, r;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &x, &r);
        v.push_back(make_pair(x - r, 0));
        v.push_back(make_pair(x + r, 1));
    }
    sort(v.begin(), v.end());
    int sol = N, cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 0) {
            if (++cnt > 1)
                sol--;
        }
        else
            cnt--;
    }
    printf("%d\n", sol);
    return 0;
}
