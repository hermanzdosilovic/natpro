#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string number;

int main()
{
    cin >> number;
    string old = number;
    int len = number.size(), i;
    for(i = len - 2; i >= 0; i--)
        if(number[i] < number[i + 1])
            break;
    if(i >= 0)
    {
        int minn = i + 1;
        for(int j = i + 2; j < len; j++)
            if(number[i] < number[j] && number[j] < number[minn])
                minn = j;
        swap(number[i], number[minn]);
        sort(number.begin() + i + 1, number.end());
    }

    if(!old.compare(number))
        cout << "impossible" << endl;
    else
        cout << number << endl;
    return 0;
}
