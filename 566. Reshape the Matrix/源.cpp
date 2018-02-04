#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int o_r = nums.size();
		if (o_r == 0)
			return nums;

		int o_c = nums[0].size();

		if (o_r * o_c != r * c)
			return nums;

		vector<int> temp;
		for (int i = 0; i != o_r; ++i)
		{
			for (int j = 0; j != o_c; ++j)
			{
				temp.push_back(nums[i][j]);
			}
		}

		vector<vector<int>> ans(r);
		for (int i = 0; i != r; ++i)
		{
			ans[i] = vector<int>(c);
		}

		int count = 0;
		for (int i = 0; i != r; ++i)
		{
			for (int j = 0; j != c; ++j)
			{
				ans[i][j] = temp[count++];
			}
		}
		return std::move(ans);
	}
};