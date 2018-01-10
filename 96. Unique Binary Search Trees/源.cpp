#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; ++i)
		{
			for (int root = 1; root <= i; ++root)
			{
				dp[i] += dp[root - 1] * dp[i - root];
			}
		}
		return dp[n];
	}



};

int main()
{
	Solution s;

	cout << s.numTrees(1) << endl;
	cout << s.numTrees(2) << endl;
	cout << s.numTrees(3) << endl;
	cout << s.numTrees(4) << endl;

	return 0;
}