/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i != nums.size(); ++i)
		{
			int temp = target - nums[i];
			//std::cout << (map.find(temp) == map.end()) << std::endl;
			if (map.find(temp) != map.end())
			{
				return vector<int> { map.at(temp), i };
			}
			else
			{
				map[nums[i]] = i;
			}
		}
		return vector<int>();
	}
};


int main()
{
	vector<int> nums {2, 7, 11, 15};
	Solution s;
	vector<int> result = s.twoSum(nums, 9);
	std::cout << result.size();
	for (int i = 0; i != result.size(); ++i)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;

}