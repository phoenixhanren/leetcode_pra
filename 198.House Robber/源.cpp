#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		vector<vector<int>> dp(nums.size());
		dp[0].push_back(0);
		dp[0].push_back(nums[0]);
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i].push_back(max(dp[i - 1][0], dp[i - 1][1]));
			dp[i].push_back(dp[i - 1][0] + nums[i]);
		}
		return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);

	}

	int robSpace(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		int prevs_no = 0;
		int prevs_yes = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			int temp = max(prevs_no, prevs_yes);
			prevs_yes = max(prevs_no + nums[i], prevs_yes);
			prevs_no = temp;
		}
		return max(prevs_no, prevs_yes);
	}
};

int main()
{

}