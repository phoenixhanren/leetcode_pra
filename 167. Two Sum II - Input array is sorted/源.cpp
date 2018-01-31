#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//a two-pointer way
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0; 
		int right = numbers.size() - 1;

		while (true)
		{
			int temp_sum = numbers[left] + numbers[right];
			if (temp_sum == target)
			{
				return { left + 1, right + 1 };
			}
			else if (temp_sum > target)
			{
				--right;
			}
			else
			{
				++left;
			}
		}


	}

	vector<int> twoSumBinarySearch(vector<int>& numbers, int target) {
		int n = numbers.size();
		for (int i = 0; i < n; ++i)
		{
			int temp_target = target - numbers[i];
			if (*lower_bound(numbers.begin(), numbers.end(), temp_target) == temp_target)
			{
				for (int j = i + 1; j < n; ++j)
				{
					if (numbers[j] == temp_target)
					{
						return { i + 1, j + 1 };
					}
				}
			}
		}
	}

};