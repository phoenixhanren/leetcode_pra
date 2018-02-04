#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {

	struct pair_hash
	{
		size_t operator()(const pair<int, int> & p) const {
			return hash<int>()(p.first) + hash<int>()(p.second);
		}
	};

public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0)
			return 0;

		unordered_map<int, int> n_map;

		for (int i = 0; i != nums.size(); ++i)
		{
			++n_map[nums[i]];
		}
		unordered_set<pair<int, int>, pair_hash> p_set;

		for (int i = 0; i != nums.size(); ++i)
		{
			--n_map[nums[i]];
			if (n_map[nums[i] + k] > 0)
			{
				int left = nums[i], right = left + k;
				if (left > right)
					swap(left, right);
				p_set.insert(make_pair(left, right));
			}
			++n_map[nums[i]];

		}
		return p_set.size();

	}
};

int main()
{
	Solution s;
	vector<int> test_case1{ 1, 3, 1, 5, 4 };
	s.findPairs(test_case1, 0);
	return 0;
}