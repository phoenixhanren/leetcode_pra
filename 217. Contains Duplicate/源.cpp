#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> nums_map;

		for (auto n : nums)
		{
			if (nums_map.find(n) != nums_map.end())
				return true;
			nums_map[n] = 1;
		}
		return false;
	}
};