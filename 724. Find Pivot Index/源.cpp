#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);

		int left = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (left == sum - left - nums[i])
				return i;
			left += nums[i];
		}

		return -1;
	}
};