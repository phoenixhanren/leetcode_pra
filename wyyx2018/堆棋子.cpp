#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    vector<int> res(n, 0);
    vector<vector<vector<int>>> distance(n, vector<vector<int>>(n, vector<int>(n, 0)));
    
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        row[i] = temp;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        col[i] = temp;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                distance[i][j][k] = abs(row[i] - row[k]) + abs(col[j] - col[k]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sort(distance[i][j].begin(), distance[i][j].end());
        }
    }

    res[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        int min_v = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                int count = 0;
                for (int w = 0; w <= i; ++w)
                {
                    count += distance[j][k][w];
                }
                min_v  = min(min_v, count);
            }
        }
        res[i] = min_v;
    }

    cout << res[0];
    for (int i = 1; i < n; ++i)
    {
        cout << " " << res[i];
    }
    cout << endl;
    return 0;
}

