#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<set>

using namespace std;

int n, m;
int x[53];
map<int,int> c;
bool bio[32000];
vector<int> prosti;
int brProstih;
int p;
long long sol;

void generiraj_proste() {
    int i, j;
    for(i = 2; i < 32000; ++i) {
        if(bio[i] == 1)
            continue;
        prosti.push_back(i);
        for(j = i*2; j < 32000; j += i)
            bio[j] = 1;
    }
}

bool cmp(int x, int y) {
    int c1 = 0, c2 = 0;
    while(x % p == 0) {
        c1++;
        x /= p;
    }
    while(y % p == 0) {
        c2++;
        y /= p;
    }
    return c1 > c2;
}

int main()
{
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    scanf("%d", &m);
    generiraj_proste();
    brProstih = prosti.size();
    for(i = 0; i < n; ++i) {
        int temp = x[i];
        for(j = 0; j < brProstih && temp > 1; ++j)
            while(temp % prosti[j] == 0) {
                temp /= prosti[j];
                c[prosti[j]]++;
            }
        if(temp > 1) {
            prosti.push_back(temp);
            c[temp]++;
        }
    }
    sort(prosti.begin(), prosti.end());
    brProstih = prosti.size();
    for(i = 0; i < brProstih; ++i) {
        if(c[prosti[i]])
            sol++;
        p = prosti[i];
        while(c[p]) {
            sol++;
            int tmp = 0;
            sort(x, x + n, cmp);
            for(j = 0; j < n && tmp < m; ++j) {
                if(x[j] % p == 0) {
                    tmp++;
                    x[j] /= p;
                    c[p]--;
                }
            }
        }
    }
    printf("%lld\n", sol);
    return 0;
}
