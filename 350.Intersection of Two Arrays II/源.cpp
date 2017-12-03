#include <vector>
#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersectFoo(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;

		ans.clear();
		list<int> l_nums1(nums1.begin(), nums1.end());
		list<int> l_nums2(nums2.begin(), nums2.end());
		bool findOne = false;
		for (auto iter1 = l_nums1.begin(); iter1 != l_nums1.end();)
		{
			findOne = false;
			for (auto iter2 = l_nums2.begin(); iter2 != l_nums2.end(); ++iter2)
			{
				if (*iter1 == *iter2)
				{
					ans.push_back(*iter1);
					iter1 = l_nums1.erase(iter1);
					iter2 = l_nums2.erase(iter2);
					findOne = true;
					break;
				}
			}
			if (!findOne)
			{
				++iter1;
			}
		}
		return move(ans);
	}

	vector<int> intersectSorted(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		auto nums1_iter = nums1.begin();
		auto nums1_end = nums1.end();
		auto nums2_iter = nums2.begin();
		auto nums2_end = nums2.end();

		vector<int> ans;

		while (nums1_iter != nums1_end && nums2_iter != nums2_end)
		{
			if (*nums1_iter == *nums2_iter)
			{
				ans.push_back(*nums1_iter);
				++nums1_iter;
				++nums2_iter;
			}
			else if (*nums1_iter > *nums2_iter)
			{
				++nums2_iter;
			}
			else
			{
				++nums1_iter;
			}
		}
		return ans;

	}

	vector<int> intersectHash(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;

		if (nums1.size() > nums2.size())
		{
			ans = nums1;
			nums1 = nums2;
			nums2 = ans;
		}
		ans.clear();

		unordered_map<int, int> dict;

		for (auto iter = nums1.begin(); iter != nums1.end(); ++iter)
		{
			if (dict.find(*iter) == dict.end())
			{
				dict[*iter] = 1;
			}
			else
			{
				++dict[*iter];
			}
		}

		for (auto iter = nums2.begin(); iter != nums2.end(); ++iter)
		{
			if (dict.find(*iter) != dict.end() && --dict[*iter] >= 0)
			{
				ans.push_back(*iter);
			}
		}
		return move(ans);
	}
};

int main()
{
	Solution s;
	//vector<int> ans = s.intersectFoo(vector<int>({ 2, 2, 2, 1 }), vector<int>({ 2, 2 }));
	//vector<int> ans = s.intersectSorted(vector<int>({ 2, 2, 2, 1 }), vector<int>({ 2, 2 }));
	vector<int> ans = s.intersectHash(vector<int>({ 2, 2, 2, 1 }), vector<int>({ 2, 2 }));
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;

	//unordered_map<int, int> test;

	//int temp = test[2];

	//cout << temp << endl;

	//cout << endl;
}

