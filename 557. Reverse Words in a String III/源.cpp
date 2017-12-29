#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		if (s.size() == 0)
			return s;

		char space = ' ';
		int offset = 0;
		stringstream ss;
		stringbuf * s_buf = ss.rdbuf();
		int i = 0;
		string sub_str;
		for (; i < s.length(); i += (offset + 1))
		{
			offset = s.find_first_of(space, i);
			if (offset == string::npos)
			{
				break;
			}
			offset -= i;
			sub_str = s.substr(i, offset);
			reverse(sub_str.begin(), sub_str.end());
			s_buf->sputn(sub_str.c_str(), sub_str.length());
			s_buf->sputc(space);
		}
		sub_str = string(s.begin() + i, s.end());
		reverse(sub_str.begin(), sub_str.end());
		s_buf->sputn(sub_str.c_str(), sub_str.length());

		return ss.str();
	}
};

int main()
{
	string test_case("Let's take LeetCode contest");
	Solution s;
	//cout << s.reverseWords(test_case) << endl;
	string test_case1("");
	//cout << s.reverseWords(test_case1) << endl;
	string test_case2("a b d ee$#% aef$ea eaef eaj ae##ea'fe");
	cout << s.reverseWords(test_case2) << endl;
	return 0;
}