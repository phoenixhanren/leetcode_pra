#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int n = nums.size();
		int max_ones = 0;
		int curr_ones = 0;

		for (auto iter : nums)
		{
			if (iter == 0)
			{
				max_ones = max_ones > curr_ones ? max_ones : curr_ones;
				curr_ones = 0;
			}
			else
			{
				++curr_ones;
			}
		}
		max_ones = max_ones > curr_ones ? max_ones : curr_ones;
		return max_ones;
	}
};