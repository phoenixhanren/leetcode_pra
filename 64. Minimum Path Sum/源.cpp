#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m);
		dp[0].push_back(grid[0][0]);
		for (int j = 1; j < n; ++j)
		{
			dp[0].push_back(dp[0][j - 1] + grid[0][j]);
		}

		for (int i = 1; i < m; ++i)
		{
			dp[i].push_back(dp[i - 1][0] + grid[i][0]);
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i].push_back(min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]);
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	vector<vector<int>> test_case1(
								{ {1, 3, 1},
								  {1, 5, 1},
								  {4, 2, 1}
								});

	Solution s;

	cout << s.minPathSum(test_case1) << endl;

	return 0;
}