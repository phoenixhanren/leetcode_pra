#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		int a_s = a.length();
		int b_s = b.length();

		if (a_s != b_s)
			return max(a_s, b_s);

		if (a == b)
			return -1;

		return b_s;



	}
};