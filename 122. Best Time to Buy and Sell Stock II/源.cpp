#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
		{
			return 0;
		}

		int max_profit = 0;
		int buy = prices[0];

		for (int i = 1; i < n; ++i)
		{
			if (prices[i] >= buy)
			{
				max_profit += prices[i] - buy;
				buy = prices[i];
			}
			else
			{
				buy = prices[i];
			}
		}
		return max_profit;
	}
};