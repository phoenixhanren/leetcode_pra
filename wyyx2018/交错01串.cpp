#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    if (len <= 1)
    {
        cout << len << endl;
        return 0;
    }

    int curr_max = 1;
    int total_max = 1;

    for (int i = 1; i < len; ++i)
    {
        if (s[i] != s[i - 1])
        {
            ++curr_max;
        }
        else
        {
            total_max = max(curr_max, total_max);
            curr_max = 1;
        }
    }
    total_max = max(curr_max, total_max);
    cout << total_max << endl;
    return 0;
}