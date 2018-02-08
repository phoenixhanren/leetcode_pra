#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = vector<bool>(n, false);
        }
        string ans = "";
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]))
                    dp[i][j] = true;

                if (dp[i][j] && j - i + 1 >= ans.length())
                    ans = s.substr(i, j - i);
            }
        }
        return ans;
    }
};