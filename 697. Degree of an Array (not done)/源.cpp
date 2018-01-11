#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	/*
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> nums_map;
		unordered_map<int, int> sub_map;
		for (auto n : nums)
		{
			++nums_map[n];
		}
		//int max_val = nums[0];
		int max_count = INT_MIN;
		for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
		{
			max_count = max_count > iter->second ? max_count : iter->second;
		}
		for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
		{
			if (iter->second == max_count)
			{
				sub_map[iter->first] = max_count;
			}
		}
		nums_map.clear();
		for (auto i = nums.begin(); i != nums.end(); ++i)
		{
			for (auto iter = sub_map.begin(); iter != sub_map.end(); ++iter)
			{
				//if (iter->second != 0 )
				//{
				//	++nums_map[iter->first];
				//}
				if (*i == iter->first)
				{
					--sub_map[iter->first];
				}
				if (iter->second != max_count && iter->second >= 0)
				{
					++nums_map[iter->first];
					if (iter->second == 0)
						--sub_map[iter->first];
					
				}
			}
		}

		int min_length = INT_MAX;
		for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
		{
			min_length = iter->second < min_length ? iter->second : min_length;
		}

		return min_length;
	}
	*/

	/*
	Just record the index of each number in a hash map and find the degree of the array. 
	Second iteration to find the shortest index range for the number with the largest frequency.
	*/
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, vector<int>> nums_map;
		int n = nums.size();
		for (int i = 0; i != n; ++i)
		{
			nums_map[nums[i]].push_back(i);
		}
		int degree = 0;
		for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
		{
			degree = max(static_cast<int>(iter->second.size()), degree);
		}
		int length = nums.size();
		for (auto iter = nums_map.begin(); iter != nums_map.end(); ++iter)
		{
			if (iter->second.size() == degree)
			{
				length = min(length, iter->second[degree - 1] - iter->second[0] + 1);
			}
		}
		return length;
	}
};

int main()
{
	vector<int> test_case1({ 1, 2, 2, 3, 1 });
	vector<int> test_case2({ 1, 2, 2, 3, 1, 4, 2 });

	Solution s;

	cout << s.findShortestSubArray(test_case1) << endl;
	cout << s.findShortestSubArray(test_case2) << endl;

	return 0;
}