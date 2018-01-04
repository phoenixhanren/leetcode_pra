#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n == 0)
			return 0;

		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = s[0] != '0' ? 1 : 0;
		for (int i = 2; i <= n; ++i)
		{
			int first = stoi(s.substr(i - 1, 1));
			int second = stoi(s.substr(i - 2, 2));
			if (first >= 1 && first <= 9)
			{
				dp[i] += dp[i - 1];
			}
			if (second >= 10 && second <= 26)
			{
				dp[i] += dp[i - 2];
			}
		}
		return dp[n];
	}
	//int numDecodings(string s) {
	//	int n = s.length();
	//	if (n == 0)
	//		return 0;
	//	vector<vector<int>> dp(n);
	//	for (int i = 0; i != n; ++i)
	//	{
	//		vector<int> temp(n, 0);
	//		dp[i] = temp;
	//	}
	//	for (int i = n - 1; i >= 0; --i)
	//	{
	//		if (s[i] == '0' && (i == 0 || s[i - 1] != '1'))
	//		{
	//			return 0;
	//		}
	//		for (int j = i; j < n; ++j)
	//		{
	//			if (i == j)
	//			{
	//				if (s[i] == '0')
	//				{
	//					dp[i][j] = 0;
	//				}
	//				else
	//				{
	//					dp[i][j] = 1;
	//				}			
	//				//++count;
	//			}
	//			else
	//			{
	//				string sub_str = s.substr(j - 1, 2);
	//				char decode_c = stoi(sub_str) - 1 + 'A';
	//				if (decode_c >= 'A' && decode_c <= 'Z' && sub_str != "01" && sub_str != "10")
	//				{
	//					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;		
	//				}
	//				else
	//				{
	//					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
	//				}
	//			}

	//		}
	//	}
	//	return dp[0][n - 1];
	//}



};

int main()
{
	string test_case1("12");
	string test_case2("6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155");
	string test_case3("10");
	string test_case4("110");
	string test_case5("101");

	Solution s;

	cout << s.numDecodings(test_case1) << endl;
	cout << s.numDecodings(test_case2) << endl;
	cout << s.numDecodings(test_case3) << endl;
	cout << s.numDecodings(test_case4) << endl;
	cout << s.numDecodings(test_case5) << endl;
	return 0;
}