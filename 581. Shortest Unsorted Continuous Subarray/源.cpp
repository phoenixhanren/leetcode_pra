#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//silly...modified case by case
	/*int findUnsortedSubarray(vector<int>& nums) {
		int s = 1;
		int e = 0;
		int n = nums.size();
		if (n == 0 || n == 1)
			return 0;

		bool s_find = false;
		int s_val = -1;
		int min_val = INFINITY;
		int max_val = -INFINITY;

		for (int i = 1; i < n; ++i)
		{
			if (nums[i - 1] > nums[i])
			{
				min_val = nums[i] < min_val ? nums[i] : min_val;
				max_val = nums[i - 1] > max_val ? nums[i - 1] : max_val;

				if (s_find)
				{
					e = i;
					for (int j = s - 1; j >= 0; --j)
					{
						if (nums[j] > nums[e])
							--s;
						else
						{
							break;
						}
					}
				}
				else
				{
					s = i - 1;
					s_find = true;
					e = i;
					s_val = nums[i - 1];
					for (int j = s - 1; j >= 0; --j)
					{
						if (nums[j] > nums[e])
							--s;
						else
						{
							break;
						}
					}

				}
			}
			else
			{
				if (nums[i] < s_val ||  nums[i] < max_val)
					e = i;
			}
		}
		return e - s + 1;
	}
	*/

	//find the max from the left and min from the right
	/**
	The idea is that:

	From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
	From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;
	*            /------------\\
	* nums:  [2, 6, 4, 8, 10, 9, 15]
	* minr:   2  4  4  8   9  9  15
	*         <--------------------
	* maxl:   2  6  6  8  10 10  15
	*         -------------------->
	*/
	int findUnsortedSubarray(vector<int>& nums) {
		int s = 0, e = -1, min_val = INT_MAX , max_val = INT_MIN;

		for (int l = 0, r = nums.size() - 1; r >= 0; l++, r--)
		{
			max_val = nums[l] > max_val ? nums[l] : max_val;
			if (max_val != nums[l])
				e = l;

			min_val = nums[r] < min_val ? nums[r] : min_val;
			if (min_val != nums[r])
				s = r;
		}
		return e - s + 1;
	}

};

int main()
{
	vector<int> test_case1{ 2, 6, 4, 8, 10, 9, 15 };
	Solution s;
	cout << s.findUnsortedSubarray(test_case1) << endl;
	
	return 0;
}