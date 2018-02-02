#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans(digits.rbegin(), digits.rend());
		int add_on = 0;

		ans[0] += 1;
		if (ans[0] >= 10)
		{
			add_on = 1;
			ans[0] %= 10;
		}

		for (int i = 1; i < ans.size(); ++i)
		{
			ans[i] += add_on;

			if (ans[i] >= 10)
			{
				add_on = 1;
				ans[i] %= 10;
			}
			else
			{
				add_on = 0;
			}
		}
		if (add_on != 0)
		{
			ans.push_back(add_on);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};