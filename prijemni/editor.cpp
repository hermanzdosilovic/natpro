#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<string, string> ps;

ps commands[10004];
bool disabled[10004];

int main()
{
    int N;
    string command, value;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        cin >> command;
        cin >> value;
        commands[i] = make_pair(command, value);
    }
    int cnt = 0;
    for(int i = N - 1; ~i; i--)
    {
        if(!cnt && !commands[i].x.compare("undo"))
        {
            cnt = atoi(commands[i].y.c_str());
            disabled[i] = true;
        }
        else if(cnt)
        {
            cnt--;
            disabled[i] = true;
        }
    }

    vector<string> word;
    int p = 0;
    for(int i = 0; i < N; i++)
    {
        if(disabled[i])
            continue;
        if(!commands[i].x.compare("type"))
        {
            word.insert(word.begin() + p, commands[i].y);
            p++;
        }
        else if(!commands[i].x.compare("right"))
        {
            int value = atoi(commands[i].y.c_str());
            p = min(p + value, (int)word.size());
        }
        else
        {
            int value = atoi(commands[i].y.c_str());
            p = max(0, p - value);
        }
    }
    for(int i = 0; i < word.size(); i++)
        cout << word.at(i);
    cout << endl;
    return 0;
}
