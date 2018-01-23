#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		
		int max_1 = INT_MIN;
		int max_2 = INT_MIN;
		int max_3 = INT_MIN;

		int min_1 = INT_MAX;
		int min_2 = INT_MAX;

		for (auto n : nums)
		{
			if (n > max_1)
			{
				max_3 = max_2;
				max_2 = max_1;
				max_1 = n;
			}
			else if (n > max_2)
			{
				max_3 = max_2;
				max_2 = n;
			}
			else if (n > max_3)
			{
				max_3 = n;
			}

			if (n < min_1)
			{
				min_2 = min_1;
				min_1 = n;
			}
			else if (n < min_2)
			{
				min_2 = n;
			}

		}
		return max(max_3 * max_2 * max_1, max_1 * min_1 * min_2);

		//int arr[3]{ nums[0], nums[1], nums[2] };
		//arr[0] = nums[0];
		//arr[1] = nums[1];
		//arr[2] = nums[2];
		//pair<int, int> min_pair = make_min();

		//for (int i = 3; i < nums.size(); ++i)
		//{
		//	if (min_pair.second < nums[i])
		//	{
		//		arr[min_pair.first] = nums[i];
		//	}
		//}
		//return arr[0] * arr[1] * arr[2];

		//int pro = nums[0] * nums[1] * nums[2];
		//int last_pro = nums[0] * nums[1] * nums[2];
		//int index[3] = { 0, 1, 2 };

		//for (int i = 3; i < nums.size(); ++i)
		//{
		//	int first = nums[i] * nums[index[1]] * nums[index[2]];
		//	int second = nums[i] * nums[index[0]] * nums[index[2]];
		//	int third = nums[i] * nums[index[1]] * nums[index[0]];

		//	if (first > second && first > third)
		//	{
		//		if (first > last_pro)
		//		{
		//			last_pro = first;
		//			index[0] = i;
		//		}
		//	}
		//	else if (second > first && second > third)
		//	{
		//		if (second > last_pro)
		//		{
		//			last_pro = second;
		//			index[1] = i;
		//		}
		//	}
		//	else
		//	{
		//		if (third > last_pro)
		//		{
		//			last_pro = third;
		//			index[2] = i;
		//		}
		//	}
		//}
		//return last_pro;

	}

//private:
//	int arr[3];
//	pair<int, int> make_min()
//	{
//		pair<int, int> ret(0, arr[0]);
//		ret = ret.second < arr[1] ? ret : pair<int, int>(1, arr[1]);
//		ret = ret.second < arr[2] ? ret : pair<int, int>(2, arr[2]);
//		return ret;
//	}
};