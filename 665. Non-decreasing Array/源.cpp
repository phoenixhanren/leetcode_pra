#include <vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int count = 1;

		for (int i = 1; i < nums.size() && count >= 0; ++i)
		{
			if (nums[i - 1] > nums[i])
			{
				--count;
				if (i - 2 < 0 || nums[i - 2] < nums[i])
				{
					nums[i - 1] = nums[i];
				}
				else
				{
					nums[i] = nums[i - 1];
				}
			}
				
		}
		return count >= 0;
	}
};