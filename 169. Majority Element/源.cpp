#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> n_map;

		for (auto iter : nums)
		{
			++n_map[iter];
		}

		int n = nums.size();
		int half_n = n / 2;
		auto max_item = n_map.begin();

		for (auto iter = n_map.begin(); iter != n_map.end(); ++iter)
		{
			if (iter->second >= half_n && iter->second > max_item->second)
			{
				max_item = iter;
			}
		}
		return max_item->first;
	}
};