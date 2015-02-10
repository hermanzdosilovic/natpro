#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pi;

vector<pi> coord;
int x[20005];
int y[20005];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1 += 10000;
        y1 += 10000;
        x2 += 10000;
        y2 += 10000;
        coord.push_back(make_pair(x1, y1));
        coord.push_back(make_pair(x2, y2));
        x[min(x1, x2)]++;
        x[max(x1, x2) + 1]--;
        y[min(y1, y2)]++;
        y[max(y1, y2) + 1]--;
    }
    sort(coord.begin(), coord.end());
    for(int i = 1; i <= 20000; i++)
    {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }
    int minX = 1 << 30;
    int maxX = -1;
    int minY = 1 << 30;
    int maxY = -1;
    for(int i = 0; i <= 20000; i++)
    {
        if(x[i] == N) {
            minX = min(minX, i);
            maxX = max(maxX, i);
        }
        if(y[i] == N) {
            minY = min(minY, i);
            maxY = max(maxY, i);
        }
    }
    printf("%d\n", abs(maxX - minX) * abs(maxY - minY));
    return 0;
}
