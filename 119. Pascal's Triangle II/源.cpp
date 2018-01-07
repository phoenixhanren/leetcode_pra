#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		vector<int> ans_temp;
		ans.resize(1);
		ans[0] = 1;
		if (rowIndex == 0)
			return ans;

		for (int i = 1; i <= rowIndex; ++i)
		{
			ans_temp = ans;
			ans.resize(i + 1);
			ans[0] = 1;
			for (int j = 1; j < i; ++j)
			{
				ans[j] = ans_temp[j - 1] + ans_temp[j];
			}
			ans[i] = 1;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> ret = s.getRow(1);
	return 0;
}