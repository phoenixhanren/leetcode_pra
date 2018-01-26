#include <vector>

using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int max_value = 0;
		int max_index = -1;

		int s_max_value = 0;

		for (int i = 0; i != nums.size(); ++i)
		{
			if (max_value < nums[i])
			{
				s_max_value = max_value;
				max_value = nums[i];
				max_index = i;
			}
			else if (s_max_value < nums[i])
			{
				s_max_value = nums[i];
			}
		}

		return (max_value >= 2 * s_max_value) ? max_index : -1;
		//if (max_value == 0 && s_max_value == 0)
		//	return -1;

		//if (s_max_value == 0)
		//	return max_index;

		//return max_value / s_max_value >= 2 ? max_index : -1;
	}
};