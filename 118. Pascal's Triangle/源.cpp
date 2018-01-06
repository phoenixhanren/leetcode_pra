#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		if (numRows == 0)
			return ans;
		for (int i = 0; i < numRows; ++i)
		{
			ans[i].resize(i + 1);
			ans[i][0] = 1;
			for (int j = 1; j < ans[i].size() - 1; ++j)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans[i][i] = 1;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	s.generate(5);
}