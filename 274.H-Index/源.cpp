#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	//O(NlogN)
	int hIndex(vector<int>& citations) {
		sort(citations.rbegin(), citations.rend());
		int ans = 0;
		for (int i = 0; i < citations.size(); ++i)
		{
			if (citations[i] >= i + 1)
			{
				ans = i + 1;
			}
		}
		return ans;
	}
	//O(N) with buckets
	int hIndexBuckets(vector<int>& citations) {
		int size = citations.size();

		vector<int> buckets(size + 1, 0);
		for (int i : citations)
		{
			if (i >= size)
				++buckets[size];
			else
			{
				++buckets[i];
			}
		}

		int result = 0;

		int count = 0;

		for (int i = size; i >= 0; --i)
		{
			count += buckets[i];
			if (count >= i)
			{
				result = i;
				break;
			}
		}
		return result;

	}

};

int main()
{
	Solution s;

	vector<int> test_case1({ 3, 0, 6, 1, 5 });
	vector<int> test_case2({ 100 });
	vector<int> test_case3({ 0 });
	vector<int> test_case4({ 0, 0 });
	vector<int> test_case5({ 11, 15 });
	cout << s.hIndex(test_case1) << endl;
	cout << s.hIndex(test_case2) << endl;
	cout << s.hIndex(test_case3) << endl;
	cout << s.hIndex(test_case4) << endl;
	cout << s.hIndex(test_case5) << endl;

	cout << s.hIndexBuckets(test_case1) << endl;
	cout << s.hIndexBuckets(test_case2) << endl;
	cout << s.hIndexBuckets(test_case3) << endl;
	cout << s.hIndexBuckets(test_case4) << endl;
	cout << s.hIndexBuckets(test_case5) << endl;

	return 0;

}
