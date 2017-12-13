#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		unordered_map<int, int> nums_map;
		sort(nums.begin(), nums.end());

		for (int i = 0; i != nums.size(); ++i)
		{
			nums_map[nums[i]] += nums[i];
		}

		auto unique_end = unique(nums.begin(), nums.end());
		vector<int> temp_nums(nums.begin(), unique_end);

		vector<vector<int>> dp(temp_nums.size());
		dp[0].push_back(0);
		dp[0].push_back(nums_map[temp_nums[0]]);
		int prev_num = temp_nums[0];
		for (int i = 1; i != temp_nums.size(); ++i)
		{
			dp[i].push_back(max(dp[i - 1][0], dp[i - 1][1]));
			if (prev_num + 1 == temp_nums[i])
			{
				dp[i].push_back(max(dp[i - 1][0] + nums_map[temp_nums[i]], dp[i - 1][1]));
			}
			else
			{
				dp[i].push_back(max(dp[i - 1][0] + nums_map[temp_nums[i]], dp[i - 1][1] + nums_map[temp_nums[i]]));
			}
			prev_num = temp_nums[i];
		}
		return max(dp[temp_nums.size() - 1][0], dp[temp_nums.size() - 1][1]);
	}

	int deleteAndEarnRobber(vector<int>& nums) {
		int gold[10001];
		for (int i = 0; i != 10001; ++i)
		{
			gold[i] = 0;
		}

		for (int i : nums)
		{
			gold[i] += i;
		}

		int prevs_no = 0;
		int prevs_yes = 0;

		for (int i = 1; i != 10001; ++i)
		{
			int temp = max(prevs_no, prevs_yes);
			prevs_yes = max(prevs_no + gold[i], prevs_yes);
			prevs_no = temp;
		}

		return max(prevs_yes, prevs_no);
	}
};

int main()
{
	vector<int> test_case1({ 3, 4, 2 });

	Solution s;

	cout << s.deleteAndEarn(test_case1) << endl;

	return 0;
}