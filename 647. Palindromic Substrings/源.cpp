#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//bottom-up
	int countSubstrings(string s) {
		int n = s.length();
		if (n == 0)
			return 0;
		vector<vector<bool>> dp(n);
		for (int i = 0; i != n; ++i)
		{
			vector<bool> temp(n, false);
			dp[i] = temp;
		}
		int count = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				dp[i][j] = s[i] == s[j] &&
					(j - i < 3 || dp[i + 1][j - 1]);
				if (dp[i][j])
					++count;
			}
		}
		return count;
	}

	//void counting(vector<vector<bool> &dp, int s, int e, 
	int countSubstringsTD(string s) {
	}
};

int main()
{
	Solution s;
	string test_case1("aaa");
	string test_case2("abc");

	cout << s.countSubstrings(test_case1) << endl;
	cout << s.countSubstrings(test_case2) << endl;

	return 0;
}