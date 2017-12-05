#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

	friend ostream & operator<<(ostream & out, const Interval & inter) {
		out << "[" << inter.start << ", " << inter.end << " ]";
		return out;
	}

};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0 || intervals.size() == 1)
			return intervals;

		sort(intervals.begin(), intervals.end(), [](const Interval & left, const Interval & right)-> bool {
			if (left.start < right.start)
				return true;
			if (left.start > right.start)
				return false;
			return left.end < right.end;
		});

		vector<Interval> ans;
		Interval temp = intervals[0];
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (temp.end < intervals[i].start)
			{
				ans.push_back(temp);
				temp = intervals[i];
			}
			else
			{
				if (temp.end < intervals[i].end)
					temp.end = intervals[i].end;
			}
		}
		ans.push_back(temp);
		return ans;
	}
};

int main()
{
	Solution s;
	vector<Interval> test_case1{ {1, 3}, {2, 6}, {8, 10}, {15, 18}};
	vector<Interval> ans = s.merge(test_case1);
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;
}