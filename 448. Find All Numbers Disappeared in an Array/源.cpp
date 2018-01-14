#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int, int> n_map;
		for (auto iter : nums)
		{
			++n_map[iter];
		}
		vector<int> ret;
		for (int i = 1; i <= n; ++i)
		{
			if (n_map[i] == 0)
				ret.push_back(i);
		}
		return ret;
	}
};