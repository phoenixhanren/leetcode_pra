#include <vector>

using namespace std;

class Solution {
public:
	void rotateCopy(vector<int>& nums, int k) {
		vector<int> temp(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i != n; ++i)
		{
			nums[(i + k) % n] = temp[i];
		}
	}

	//reverse each sub, then reverse the entire array
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;

		reverse(nums.begin(), nums.end() - k);
		reverse(nums.end() - k , nums.end());
		reverse(nums.begin(), nums.end());
	}
};