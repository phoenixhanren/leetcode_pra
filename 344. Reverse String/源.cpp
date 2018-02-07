#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		stringstream ss;

		for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
		{
			ss << *iter;
		}

		return ss.str();
	}
};