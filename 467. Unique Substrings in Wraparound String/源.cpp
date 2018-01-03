#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
	//sillyDP
	int findSubstringInWraproundStringSillyDP(string p) {
		int n = p.length();
		if (n == 0)
			return 0;
		unordered_map<string, int> ans_map;
		vector <vector<bool>> dp(n);
		for (int i = 0; i < n; ++i)
		{
			vector<bool> temp(n, false);
			dp[i] = temp;
		}
		int count = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				//cout << p.substr(i, j - i + 1) << "...";
				//cout << "p[i]" << p[i] << "...p[j]" << p[j] << "...";
				if (ans_map[p.substr(i, j - i + 1)] == 1)
				{
					dp[i][j] = true;
					continue;
				}
				if (j == i)
					dp[i][j] = true;
				else
				{
					dp[i][j] = ((p[j - 1] + 1 == p[j] || (p[j - 1] == 'z' && p[j] == 'a')) &&
						dp[i][j - 1]);
				}
				if (dp[i][j])
				{
					ans_map[p.substr(i, j - i + 1)] = 1;
					++count;
				}
					
				//cout << dp[i][j] << endl;
			}
		}
		return count;
	}

	int findSubstringInWraproundString(string p) {
		vector<int> letters(26, 0);
		int cur_len = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			if (i > 0 && (p[i - 1] + 1 == p[i] || (p[i - 1] == 'z' && p[i] == 'a')))
			{
				++cur_len;
			}
			else
			{
				cur_len = 1;
			}
			letters[p[i] - 'a'] = max(letters[p[i] - 'a'], cur_len);
		}
		
		return accumulate(letters.begin(), letters.end(), 0);
	}
};

int main()
{
	string test_case1("a");
	string test_case2("cac");
	string test_case3("zab");
	
	Solution s;

	cout << s.findSubstringInWraproundString(test_case1) << endl;
	cout << s.findSubstringInWraproundString(test_case2) << endl;
	cout << s.findSubstringInWraproundString(test_case3) << endl;

	return 0;
}