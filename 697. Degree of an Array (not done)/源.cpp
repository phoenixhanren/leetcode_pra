#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		return 0;
	}
};

int main()
{
	vector<int> test_case1({ 1, 2, 2, 3, 1 });
	vector<int> test_case2({ 1, 2, 2, 3, 1, 4, 2 });

	Solution s;

	cout << s.findShortestSubArray(test_case1) << endl;
	cout << s.findShortestSubArray(test_case2) << endl;

	return 0;
}