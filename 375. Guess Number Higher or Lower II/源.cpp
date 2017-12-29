#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
For each number x in range[i~j]
we do: result_when_pick_x = x + max{DP([i~x-1]), DP([x+1, j])}
¨C> // the max means whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
then we get DP([i~j]) = min{xi, ¡­ ,xj}
¨C> // this min makes sure that you are minimizing your cost.
inspried by https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84764/
top_down vs. bottom-up
https://cs.stackexchange.com/questions/2644/top-down-bottom-up-dynamic-programming
*/
class Solution {
public:

	//Top-down approach
	int getMoneyAmountTD(int n) {
		vector<vector<int>> dp(n + 1);
		for (int i = 0; i < n + 1; ++i)
		{
			vector<int> temp(n + 1, 0);
			dp[i] = temp;
		}
		return dpTopDown(dp, 1, n);
	}

	int dpTopDown(vector<vector<int>> &dp, int s, int e) {
		if (s >= e)
			return 0;
		if (dp[s][e] != 0)
			return dp[s][e];
		int res = INFINITY;
		for (int i = s; i <= e; ++i)
		{
			int temp = i + max(dpTopDown(dp, s, i - 1), dpTopDown(dp, i + 1, e));
			res = min(temp, res);
		}
		dp[s][e] = res;
		return res;
	}

	//Bottom-up approach
	int getMoneyAmount(int n) {

	}

};

int main()
{
	Solution s;
	cout << s.getMoneyAmount(2) << endl;
	return 0;
}