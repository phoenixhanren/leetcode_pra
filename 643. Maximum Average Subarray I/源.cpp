#include <vector>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		int max_sum = INT_MIN;
		for (int i = 0; i < k; ++i)
		{
			sum += nums[i];
		}
		max_sum = max_sum > sum ? max_sum : sum;
		//cout << sum << " " << max_sum << endl;
		for (int i = 1; i < nums.size() - k + 1; ++i)
		{
			sum = sum - nums[i - 1] + nums[i + k - 1];
			max_sum = max_sum > sum ? max_sum : sum;
			//cout << sum << " " << max_sum << endl;
		}

		return max_sum / static_cast<double>(k);
	}
};