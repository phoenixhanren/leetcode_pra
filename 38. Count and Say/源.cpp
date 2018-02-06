#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)
			return "";
		if (n == 1)
			return "1";

		string temp = countAndSay(n - 1);
		stringstream ss;
		int count = 0;
		auto iter = temp.begin();
		char last = *iter;

		//auto iter_next = ++iter;
		for (; iter != temp.end(); ++iter)
		{
			if (last == *iter)
			{
				++count;
			}
			else
			{
				ss << count << last;
				last = *iter;
				count = 1;
			}
		}
		ss << count << last;
		return ss.str();
	}
};

int main()
{
	Solution s;

	for (int i = 1; i < 6; ++i)
	{
		cout << s.countAndSay(i) << endl;
	}
	return 0;
}