#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    if (len <= 2)
    {
        cout << len << endl;
        return 0;
    }

    set<char> set;
    for (int i = 0; i < len; ++i)
    {
        set.insert(s[i]);
    }

    if (set.size() > 2)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << set.size() << endl;
    return 0;

}