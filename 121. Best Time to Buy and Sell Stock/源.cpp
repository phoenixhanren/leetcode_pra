#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		//vector<vector<int>> dp(N);
		if (N == 0)
			return 0;

		int buy = prices[0];
		int max_profit = 0;
		//bool sale = false;

		for (int i = 1; i < N; ++i)
		{
			if (buy > prices[i])
			{
				buy = prices[i];
			}
			else
			{
				max_profit = (prices[i] - buy) > max_profit ? (prices[i] - buy) : max_profit;
				//sale = true;
			}
		}
		return max_profit;
	}
};

int main()
{
	vector<int> test_case1({ 7, 1, 5, 3, 6, 4 });
	vector<int> test_case2({ 7, 6, 4, 3, 1 });

	Solution s;

	cout << s.maxProfit(test_case1) << endl;
	cout << s.maxProfit(test_case2) << endl;

	return 0;
}