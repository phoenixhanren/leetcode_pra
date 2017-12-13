#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//ducth_national_flag_problem...three way partition
	void sortColors(vector<int>& nums) {
		int i = 0;
		int j = 0;
		int n = nums.size() - 1;
		/*if (n == 0 || n == -1)
			return;
			*/
		/*if (n == 1)
		{
			if (nums[0] > nums[1])
				swap(nums[0], nums[1]);
			return;
		}*/

		int mid = 1;
		while (j <= n)
		{
			if (nums[j] < mid)
			{
				swap(nums[i], nums[j]);
				i = i + 1;
				j = j + 1;
			}
			else if (nums[j] > mid)
			{
				swap(nums[j], nums[n]);
				n = n - 1;
			}
			else
			{
				j = j + 1;
			}
		}
		return;
	}
};

int main()
{
	vector<int> test_case1({ 1, 2, 0, 1 , 0, 2 });

	Solution s;
	s.sortColors(test_case1);

	return 0;
}