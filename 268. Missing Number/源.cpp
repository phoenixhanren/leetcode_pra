#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:

	int missingNumber(vector<int>& nums) {
		int expected_sum = nums.size() * (nums.size() + 1) / 2;
		int sum = accumulate(nums.begin(), nums.end(), 0);

		return expected_sum - sum;
	}

	//bit a^b^b = a
	int missingNumberBit(vector<int>& nums) {
		int n = nums.size();

		int result = n;

		for (int i = 0; i < n; ++i)
		{
			result ^= i;
			result ^= nums[i];
		}
		return result;

	}

	int missingNumberSet(vector<int>& nums) {
		unordered_set<int> n_set;
		int n = nums.size();

		for (auto &ns : nums)
		{
			n_set.insert(ns);
		}

		for (int i = 0; i <= n; ++i)
		{
			if (n_set.find(i) == n_set.end())
			{
				return i;
			}
		}

	}
};