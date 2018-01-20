#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int index = 0;

		for (int i = 0; i < n; ++i)
		{
			if (nums[i] != 0)
			{
				nums[index++] = nums[i];
			}
		}

		for (int j = index; j < n; ++j)
		{
			nums[j] = 0;
		}

	}
};