#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int mod = 1000000007;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= k; ++i)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= k; ++j)
        {
            sum = (sum + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j] = sum;
            for (int q = j * 2; q <= k; q += j)
            {
                dp[i][j] = (dp[i][j] - dp[i - 1][q]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;

    return 0;
}