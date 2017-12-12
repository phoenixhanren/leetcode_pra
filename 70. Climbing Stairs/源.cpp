#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {

		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		vector<int> dp(n);
		dp[0] = 1;
		dp[1] = 2;

		for (int i = 2; i < n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n - 1];
	}
};

int main()
{
	Solution s;

	cout << s.climbStairs(2) << endl;
	cout << s.climbStairs(3) << endl;

	return 0;
}