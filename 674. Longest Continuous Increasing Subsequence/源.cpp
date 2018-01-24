#include <vector>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int i = 0;
		int j = 1;
		int max_length = 1;

		for (; j < n; ++j)
		{
			if (nums[j] <= nums[j - 1])
			{
				max_length = max_length >(j - i) ? max_length : (j - i);
				i = j;
			}
		}
		return max_length > (j - i) ? max_length : (j - i);

	}
};