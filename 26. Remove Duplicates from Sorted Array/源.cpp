#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int removeDuplicatesTLE(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)
			return n;
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				int j = i + 1;
				for (; j < n && nums[j] == nums[j - 1]; ++j);
				int t = i;
				for (; j < n; ++j, ++t)
				{
					nums[t] = nums[j];
				}
				n = t;
				
			}
		}
		return n;
	}
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)
			return n;
		int i = 0;
		int j = i + 1;
		for (; j < n; ++j)
		{
			if (nums[i] != nums[j])
			{
				nums[++i] = nums[j];
			}
		}


		return i + 1;

	}
};