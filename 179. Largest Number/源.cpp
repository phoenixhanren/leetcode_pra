#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {

		vector<string> s_nums;

		stringstream sstream;
		
		for (int i = 0; i != nums.size(); ++i)
		{
			sstream << nums[i];
			string temp;
			sstream >> temp;
			sstream.clear();
			sstream.str("");
			s_nums.push_back(temp);
		}

		sort(s_nums.begin(), s_nums.end(), [](const string & left, const string & right) -> bool {
			//if (left.length() == right.length())
			//	return left > right;

			string left_right = left + right;
			string right_left = right + left;

			if (left_right > right_left)
			{
				return true;
			}
			return false;


			/*if (left.length() < right.length())
			{
				//right.find_first_of(left) 
				//return right.find_last_of(left) == 0;
				int ind = right.find_last_of(left);
				if (ind + left.size() == right.length())
					return true;
				
			}

			if (left.length() > right.length())
			{
				//left.find_first_of(right)
				return !(left.find_last_of(right) == 0);
			}*/

			//auto iter_left = left.cbegin();
			//auto iter_right = right.cbegin();
			//

			//if (left.length() < right.length())
			//{
			//	while (iter_left != left.cend() && iter_right != right.cend())
			//	{
			//		if (*iter_left > *iter_right)
			//		{
			//			return true;
			//		}
			//		else if (*iter_left < *iter_right)
			//		{
			//			return false;
			//		}
			//		else
			//		{
			//			++iter_right;
			//		}
			//	}
			//	return true;
			//}

			//if (left.length() > right.length())
			//{
			//	while (iter_left != left.cend() && iter_right != right.cend())
			//	{
			//		if (*iter_left < *iter_right)
			//		{
			//			return true;
			//		}
			//		else if (*iter_left > *iter_right)
			//		{
			//			return false;
			//		}
			//		else
			//		{
			//			++iter_left;
			//		}
			//	}
			//	return true;
			//}
		});

		for (auto iter = s_nums.begin(); iter != s_nums.end(); ++iter)
		{
			sstream << *iter;
		}
		string ret;
		sstream >> ret;
		if (ret.front() == '0')
			return "0";

		return ret;
	}
};

int main()
{
	Solution s;

	vector<int> test_case1({ 3, 30, 34, 5, 9});
	vector<int> test_case2({ 0, 0 });

	//cout << s.largestNumber(test_case1) << endl;
	cout << s.largestNumber(test_case2) << endl;
	return 0;
}