#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    vector<int> s;
    int temp;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        s.push_back(temp);
    }
    if (n <= 2)
    {
        cout << "Possible" << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    int diff = s[1] - s[0];
    for (int j = 2; j < n; ++j)
    {
        if (diff != s[j] - s[j - 1])
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;

}