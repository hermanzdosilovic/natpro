#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        string p;
        cin >> p;
        stack<char> s;
        int len = p.size();
        string status = "ispravno";
        for(int i = 0; i < len; i++)
        {
            if(p[i] == '[' || p[i] == '{' || p[i] == '(')
                s.push(p[i]);
            else
            {
                if(s.empty())
                {
                    status = "neispravno";
                    break;
                }
                char c = s.top();
                if((c == '{' && p[i] == '}') || (c == '[' && p[i] == ']') || (c == '(' && p[i] == ')'))
                {
                    s.pop();
                    continue;
                }
                status = "neispravno";
                break;
            }
        }
        cout << status << endl;
    }
}
