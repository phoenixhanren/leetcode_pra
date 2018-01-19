#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsertON(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0)
			return 0;

		int index = 0;
		for (; index < n; ++index)
		{
			if (nums[index] >= target)
				return index;
		}
		return index;

	}

	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0)
			return 0;

		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;
			//if (nums[mid] == target)
			//{
			//	return target;
			//}

			if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return low;
	}

};