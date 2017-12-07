#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxNum = nums[0];
		int tempMaxNum = nums[0];
		auto iter = nums.begin();

		for (++iter; iter != nums.end(); ++iter)
		{
			if (tempMaxNum < 0)
			{
				tempMaxNum = 0;
			}
			tempMaxNum += *iter;
			if (tempMaxNum > maxNum)
			{
				maxNum = tempMaxNum;
			}
		}
		return maxNum;
	}
};

int main()
{
	Solution s;
	vector<int> test_case1({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });
	cout << s.maxSubArray(test_case1) << endl;
	return 0;
}