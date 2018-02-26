#include <vector>
#include <utility>
#include <math>

using namespace std;

class Solution {
public:
    //cannot handle dual path [[1,-3,3],[0,-2,0],[-3,-3,-3]]
    int calculateMinimumHPFAILURE(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<pair<int, int>>> dp(row);
        for (int i = 0; i < row; ++i)
        {
            dp[i] = vector<pair<int, int>>(col);
        }

        dp[0][0] = pair<int, int>(dungeon[0][0], dungeon[0][0]);

        for (int i = 1; i < col; ++i)
        {
            int second = dp[0][i - 1].second + dungeon[0][i];
            int first;
            if (dp[0][i - 1].first < 0 || second < 0)
            {
                first = min(dp[0][i - 1].first, second);
            }
            else
            {
                first = max(dp[0][i - 1].first, second);
            }
            dp[0][i] = pair<int, int>(first, second);
        }

        for (int i = 1; i < row; ++i)
        {
            int second = dp[i - 1][0].second + dungeon[i][0];
            int first;
            if (dp[i - 1][0].first < 0 || second < 0)
            {
                first = min(dp[i - 1][0].first, second);
            }
            else
            {
                first = max(dp[i - 1][0].first, second);
            }
            dp[i][0] = pair<int, int>(first, second);
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                int upper_second = dp[i - 1][j].second + dungeon[i][j];
                int left_second = dp[i][j - 1].second + dungeon[i][j];
                int upper_first;
                if (upper_second < 0 || dp[i - 1][j].first < 0)
                {
                    upper_first = min(upper_second, dp[i - 1][j].first);
                }
                else
                {
                    upper_first = max(upper_second, dp[i - 1][j].first);
                }
                int left_first;
                if (left_second < 0 || dp[i][j - 1].first < 0)
                {
                    left_first = min(left_second, dp[i][j - 1].first);
                }
                else
                {
                    left_first = max(left_second, dp[i][j - 1].first);
                }            

                if (left_first > upper_first)
                {
                    dp[i][j] = pair<int, int>(left_first, left_second);
                }
                else if (left_first < upper_first)
                {
                     dp[i][j] = pair<int, int>(upper_first, upper_second);
                }
                else
                {
                    dp[i][j] = pair<int, int>(upper_first, max(upper_second, left_second));
                }
            }
        }
        int ans = dp[row - 1][col - 1].first;
        if (ans >= 0)
            return 1;
        else 
            return abs(ans) + 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m -  1][n] = 1;

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }

        }
        return dp[0][0];
    }

};