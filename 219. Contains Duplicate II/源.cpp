#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k == 0)
			return false;

		unordered_map<int, int> n_map;

		for (int i = 0; i < n; ++i)
		{
			auto iter = n_map.find(nums[i]);
			if (iter == n_map.end())
			{
				n_map[nums[i]] = i;
			}
			else
			{
				if (abs(iter->second - i) <= k)
				{
					return true;
				}
				else
				{
					iter->second = i;
				}
			}
		}
		return false;
	}

	bool containsNearbyDuplicateTLE(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k == 0)
			return false;

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j - i <= k && j < n; ++j)
			{
				if (nums[i] == nums[j])
					return true;
			}
		}

		return false;

	}
};