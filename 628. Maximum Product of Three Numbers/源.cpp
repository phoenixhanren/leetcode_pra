#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		//int arr[3]{ nums[0], nums[1], nums[2] };
		arr[0] = nums[0];
		arr[1] = nums[1];
		arr[2] = nums[2];

		pair<int, int> min_pair = make_min();

		for (int i = 3; i < nums.size(); ++i)
		{
			if (min_pair.second < nums[i])
			{
				arr[min_pair.first] = nums[i];
			}
		}
		return arr[0] * arr[1] * arr[2];
	}
private:
	int arr[3];
	pair<int, int> make_min()
	{
		pair<int, int> ret(0, arr[0]);
		ret = ret.second < arr[1] ? ret : pair<int, int>(1, arr[1]);
		ret = ret.second < arr[2] ? ret : pair<int, int>(2, arr[2]);
		return ret;
	}
};