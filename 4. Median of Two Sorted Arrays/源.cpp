#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size();
		int n = nums2.size();

		if (m > n)
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		if (m == 0)
		{
			if (n % 2 == 0)
			{
				return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
			}
			else
			{
				return nums2[n / 2];
			}
		}

		int left = 0, right = m;
		int i, j, leftMax, rightMin;
		while (left <= right)
		{
			i = (left + right) >> 1;
			j = (m + n + 1) / 2 - i;

			if((j == 0 || i == m || nums2[j - 1] <= nums1[i]) && 
				(i == 0 || j == n || nums1[i - 1] <= nums2[j]))
			{
				break;
			}
			else if(nums2[j - 1] > nums1[i])
			{
				left = i + 1;
			}
			else if(nums1[i - 1] > nums2[j])
			{
				right = i - 1;
			}
		}

		double ans = -1;
		if ((m + n) % 2 == 0)
		{
			if (j == 0)
			{

				ans = (nums2[j] + nums1[i - 1]) / 2.0;
			}
			else if (j == n)
			{
				ans = (nums2[j - 1] + nums1[i]) / 2.0;
			}
			else
			{
				ans = (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) / 2.0;
			}

		}
		else
		{
			if (j == 0 || i == m)
			{
				ans = max(nums2[j], nums1[i - 1]);
			}
			else if (i == 0 || j == n)
			{
				ans = max(nums2[j - 1], nums1[i]);
			}
			ans = max(nums1[i - 1], nums2[j - 1]);
		}
		return ans;

	}
};


int main()
{
	vector<int> nums1{2 ,3, 4};
	vector<int> nums2{ 1 };
	Solution s;
	std::cout << s.findMedianSortedArrays(nums1, nums2) << std::endl;
	return 0;
}