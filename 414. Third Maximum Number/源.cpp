#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:

	int thirdMaxSet(vector<int>& nums) {
		set<int> top3;
		for (int num : nums)
		{
			top3.insert(num);
			if (top3.size() > 3)
				top3.erase(top3.begin());
		}
		return top3.size == 3 ? *top3.begin() : *top3.rbegin();
	}

	int thirdMax(vector<int>& nums) {
		int first_max = INT_MIN;
		int second_max = INT_MIN;
		int third_max = INT_MIN;
		int count = 0;

		for (auto n : nums)
		{
			if (n > first_max)
			{
				third_max = second_max;
				second_max = first_max;
				first_max = n;
				++count;
			}
			else if (n > second_max && n != first_max)
			{
				third_max = second_max;
				second_max = n;
				++count;
			}
			else if (n > third_max && n != second_max && n != first_max)
			{
				third_max = n;
				++count;
			}
			//cout << "1";
		}
		return count >= 3 ? third_max : first_max;
	}
};

int main()
{
	vector<int> test_case1{ 1, 2, 2, 5, 3, 5 };
	Solution s;

	cout << s.thirdMax(test_case1) << endl;
	return 0;
}