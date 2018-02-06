#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		stringstream ss;

		for (auto iter = s.begin(); iter != s.end(); ++iter)
		{
			if (isalnum(*iter))
			{
				if (isalpha(*iter))
					ss << static_cast<char>(tolower(*iter));
				else
					ss << *iter;
			}
		}

		string temp = ss.str();

		if (temp.length() == 0)
			return true;
		auto l_iter = temp.begin();
		auto r_iter = temp.rbegin();
		for ( ;l_iter != temp.end() && r_iter != temp.rend(); ++l_iter, ++r_iter)
		{
			if (*l_iter != *r_iter)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;

	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;

	return 0;

}