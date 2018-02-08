#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.length() - 1;

		while(i <= j && i < s.length() && j >= 0)
		{
			for (; i < s.length(); ++i)
			{
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
					s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
					break;
			}

			for (; j >= 0; --j)
			{
				if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
					s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
					break;
			}
			if (i >= j)
				break;

			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			++i;
			--j;
		}
		return s;
	}
};

int main()
{
	Solution s;

	cout << s.reverseVowels("hello") << endl;

	return 0;
}