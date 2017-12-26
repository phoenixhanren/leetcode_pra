#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {

		int sum = accumulate(nums.begin(), nums.end(), 0);
		vector<bool> visited(nums.size(), false);
		int target = sum / k;
		if (target * k != sum)
			return false;

		return dfs(nums, visited, 0, k - 1, target, 0, 0);

	}

	bool dfs(vector<int>& nums, vector<bool> visited, int cur_sum, int k, int target, int num_count, int search_index) {

		if (k == 0)
			return true;

		if (cur_sum == target && num_count != 0)
		{
			return dfs(nums, visited, 0, k - 1, target, 0, 0);
		}

		for (int i = search_index; i != nums.size(); ++i)
		{
			if (visited[i] == false)
			{
				visited[i] = true;

				if (dfs(nums, visited, cur_sum + nums[i], k, target, num_count + 1, i))
				{
					return true;
				}

				visited[i] = false;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;

	vector<int> test_case1({ 4, 3, 2, 3, 5, 2, 1 });
	cout << s.canPartitionKSubsets(test_case1, 4) << endl;
	return 0;
}