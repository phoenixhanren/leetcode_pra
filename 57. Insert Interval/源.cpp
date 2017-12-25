#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

	friend ostream& operator<<(ostream &os, const Interval & inter);
};

ostream& operator<<(ostream &os, const Interval & inter)
{
	os << "[" << inter.start << ", " << inter.end << "]";
	return os;
}

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.size() == 0)
			return vector<Interval>({ newInterval });

		sort(intervals.begin(), intervals.end(), [](const Interval & inter_low,
			const Interval & inter_up)-> bool {
			if (inter_low.start != inter_up.start)
				return inter_low.start < inter_up.start;
			return inter_low.end < inter_up.end;
		});
		vector<Interval> ans;

		int temp = intervals[0].start;
		int temp_up = -1;
		bool more_than_one = false;

		if (newInterval.end < intervals[0].start)
		{
			ans.push_back(newInterval);
		}

		for (Interval i : intervals)
		{
			if (more_than_one)
			{
				if (i.start > newInterval.end)
				{
					ans.push_back(Interval(temp,  newInterval.end));
					ans.push_back(i);
					temp = i.end;
					more_than_one = false;
				}
				else if (i.end >= newInterval.end || i.start == newInterval.end)
				{
					ans.push_back(Interval(temp, i.end));
					temp = i.end;
					more_than_one = false;
				}
			}
			else
			{
				if (i.start > newInterval.end || i.end < newInterval.start
					|| (i.start <= newInterval.start && i.end >= newInterval.end))
				{
					if (newInterval.start > temp && newInterval.end < i.start)
						ans.push_back(newInterval);
					ans.push_back(i);
					temp = i.end;
				}
				else if (i.end < newInterval.end || i.start > newInterval.start)
				{
					temp = min(newInterval.start,i.start);
					newInterval.end = max(newInterval.end, i.end);
					more_than_one = true;
				}

			}
		}
		if (more_than_one)
		{
			ans.push_back(Interval(temp, newInterval.end));
		}
		if (ans[ans.size() - 1].end < newInterval.start)
		{
			ans.push_back(newInterval);
		}

		return ans;
	}

	vector<Interval> insertNew(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ans;
		int i = 0;

		for (; i < intervals.size() && intervals[i].end < newInterval.start; ++i)
		{
			ans.push_back(intervals[i]);
		}

		Interval temp = newInterval;
		//temp.start = newInterval.start;
		for (; i < intervals.size() && intervals[i].start <= newInterval.end; ++i) 
		{
			temp.start = min(temp.start, intervals[i].start);
			temp.end = max(intervals[i].end, newInterval.end);
		}
		ans.push_back(temp);

		for (; i < intervals.size(); ++i)
		{
			ans.push_back(intervals[i]);
		}
		return ans;
	}
};

int main()
{
	Solution s;

	vector<Interval> test_case1({
					Interval(6, 9),
					Interval(1, 3)
				});

	vector<Interval> test_case2({
		Interval(1, 2),
		Interval(3, 5),
		Interval(6, 7),
		Interval(8, 10),
		Interval(12, 16)
	});

	vector<Interval> ans1 = s.insert(test_case1, Interval(2, 5));

	for (Interval & i : ans1)
	{
		cout << i << " ";
	}
	cout << endl;

	vector<Interval> ans2 = s.insert(test_case2, Interval(4, 9));

	for (Interval & i : ans2)
	{
		cout << i << " ";
	}
	cout << endl;

	vector<Interval> test_case3({
		Interval(1, 5),
		Interval(6, 8)

	});
	vector<Interval> ans3 = s.insert(test_case3, Interval(5, 6));
	for (Interval & i : ans3)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}