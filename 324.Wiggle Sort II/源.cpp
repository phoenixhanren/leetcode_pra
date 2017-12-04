#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//virtual indexing
	//We want to place any a group of numbers (larger than median) in odd slots, and another group of numbers (smaller than median) in even slots.
	//
	void wiggleSort(vector<int>& nums) {
		auto mid_iter = nums.begin() + nums.size() / 2;
		int num_size = nums.size();
		random_shuffle(nums.begin(), nums.end());
		nth_element(nums.begin(), mid_iter, nums.end());

		int mid_value = *mid_iter;
		//cout << "mid_value..." << mid_value << endl;

		//#define B(i) nums[(2 * i) % 
	    #define A(i) nums[(1 + 2 * i) % (num_size | 1)]

		//three-way-partitioning
		int i = 0;
		int j = 0;
		int n = num_size - 1;

		while (j <= n)
		{
			//if (nums[j] < mid_value)
			if (A(j) > mid_value)
			{
				//swap(nums[i++], nums[j++]);
				swap(A(i++), A(j++));
			}
			//else if (nums[j] > mid_value)
			else if (A(j) < mid_value)
			{
				//swap(nums[j], nums[n--]);
				swap(A(j), A(n--));
			}
			else
			{
				++j;
			}
		}


	}

	//Time O(NLog(N)) Space O(N)
	void wiggleSortOLogN(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](int left, int right) -> bool {return left > right; });
		vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
		vector<int> right(nums.begin() + nums.size() / 2, nums.end());

		vector<int> ans;
		int i = 0, j = 0;
		for (; i < left.size() && j < right.size(); ++i, ++j)
		{
			ans.push_back(right[j]);
			ans.push_back(left[i]);
		}

		for (; i < left.size(); ++i)
		{
			ans.push_back(left[i]);
		}
		for (; j < right.size(); ++j)
		{
			ans.push_back(right[j]);
		}
		nums = ans;
	}

#pragma region fool_first_attempt_failed
	/*
	if (nums.size() == 1)
		return;
	if (nums.size() == 2)
	{
		if (nums[0] > nums[1])
		{
			int temp = nums[0];
			nums[0] = nums[1];
			nums[1] = temp;
		}
		return;
	}
	bool big_flag = false;
	bool is_break = false;
	for (size_t i = 0; i < nums.size() - 1; ++i)
	{
		int temp_ind = i + 1;
		is_break = false;
		if (big_flag)
		{
			if (!(nums[temp_ind] < nums[i]))
			{
				for (size_t j = temp_ind + 1; j < nums.size(); ++j)
				{
					if (nums[j] < nums[i])
					{
						int temp = nums[j];
						nums[j] = nums[temp_ind];
						nums[temp_ind] = temp;
						is_break = true;
						break;
					}
				}
			}
			else
			{
				is_break = true;
			}
		}
		else
		{
			if (!(nums[temp_ind] > nums[i]))
			{
				for (size_t j = temp_ind + 1; j < nums.size(); ++j)
				{
					if (nums[j] > nums[i])
					{
						int temp = nums[j];
						nums[j] = nums[temp_ind];
						nums[temp_ind] = temp;
						is_break = true;
						break;
					}
				}
			}
			else
			{
				is_break = true;
			}
		}
		big_flag = !big_flag;
	}

	if (!is_break)
	{
		if (big_flag)
		{
			int temp = nums[nums.size() - 1];
			nums[nums.size() - 1] = nums[nums.size() - 2];
			nums[nums.size() - 2] = temp;
		}
	}*/
#pragma endregion


};

int main()
{
	Solution s;

	vector<int> test_case1({ 1, 5, 1, 1, 6, 4 });
	vector<int> test_case2({ 1, 3, 2, 2, 3, 1 });
	
	//s.wiggleSortOLogN(test_case1);
	//s.wiggleSortOLogN(test_case2);

	s.wiggleSort(test_case1);
	s.wiggleSort(test_case2);

	for_each(test_case1.begin(), test_case1.end(), [](int i)-> void {cout << i << " "; });
	cout << endl;
	for_each(test_case2.begin(), test_case2.end(), [](int i) -> void {cout << i << " "; });
	cout << endl;
}