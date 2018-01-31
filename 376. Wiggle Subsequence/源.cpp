#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();

		if (n < 2)
			return n;
		
		int sub = nums[1] - nums[0];
		int length = sub ? 2 : 1;
		int last_index = 1;
		for (int i = 2; i < n; ++i)
		{
			int sub_temp = nums[i] - nums[last_index];
			if (sub * sub_temp < 0 || (sub == 0 && sub_temp != 0))
			{
				sub = sub_temp;
				++length;
				last_index = i;
			}
			else
			{
				last_index = i;
			}
		}
		return length;
	}
};

int main()
{
	vector<int> test_case{ 33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15
	};
	vector<int> test_case1{ 33,53,12,64,50,41,45 };

	Solution s;

	cout << s.wiggleMaxLength(test_case1);

	return 0;
	
}