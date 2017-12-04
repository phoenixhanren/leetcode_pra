#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}

		if (n == 0)
		{
			return;
		}

		vector<int> nums1_temp(nums1.begin(), nums1.begin() + m);
		nums1.clear();

		int i = 0;
		int j = 0;

		while (i < m && j < n)
		{
			if (nums1_temp[i] < nums2[j])
			{
				nums1.push_back(nums1_temp[i++]);
			}
			else if (nums1_temp[i] > nums2[j])
			{
				nums1.push_back(nums2[j++]);
			}
			else
			{
				nums1.push_back(nums1_temp[i++]);
				nums1.push_back(nums2[j++]);
			}
		}

		while (i < m)
		{
			nums1.push_back(nums1_temp[i++]);
		}

		while (j < n)
		{
			nums1.push_back(nums2[j++]);
		}
	}
};