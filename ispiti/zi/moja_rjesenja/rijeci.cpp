#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

map<string, bool> m;
map<string, bool> bio;
queue<pair<string, int> > q;
vector<string> word;

int solve(int a, int b) {
    string begin = word[a - 1];
    string finish = word[b - 1];
    bio.clear();
    bio[begin] = true;
    q.push(make_pair(begin, 0));
    int sol = INF;
    while (!q.empty()) {
        string s = q.front().first;
        int d = q.front().second;
        q.pop();
        if (!s.compare(finish))
            sol = min(sol, d);
        // promijeniti jedno slovo u drugo
        for (int i = 0; i < s.size(); i++) {
            for (int c = 'a'; c <= 'z'; c++) {
                string tmp = s;
                tmp[i] = c;
                if (!bio[tmp] && m[tmp]) {
                    bio[tmp] = true;
                    q.push(make_pair(tmp, d + 1));
                }
            }
        }
        // izbrisati neko slovo
        for (int i = 0; i < s.size(); i++) {
            string tmp = s;
            tmp.erase(i, 1);
            if (!bio[tmp] && m[tmp]) {
                bio[tmp] = true;
                q.push(make_pair(tmp, d + 1));
            }
        }
        // dodati neko slovo na neko mjesto
        for (int i = 0; i <= s.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string tmp = s;
                char pc[2];
                sprintf(pc, "%c", c);
                tmp.insert(i, pc);
                if (!bio[tmp] && m[tmp]) {
                    bio[tmp] = true;
                    q.push(make_pair(tmp, d + 1));
                }
            }
        }
    }
    return sol;
}

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s] = true;
        word.push_back(s);
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", solve(a, b));
    }
    return 0;
}
