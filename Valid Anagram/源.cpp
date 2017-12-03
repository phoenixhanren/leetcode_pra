#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> dict;
		if (s.length() != t.length())
		{
			return false;
		}

		for (auto iter = s.begin(); iter != s.end(); ++iter)
		{
			if (dict.find(*iter) == dict.end())
			{
				dict[*iter] = 1;
			}
			else
			{
				++dict[*iter];
			}
		}
		for (auto iter = t.begin(); iter != t.end(); ++iter)
		{
			if (dict.find(*iter) == dict.end() || --dict[*iter] < 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;

	cout << s.isAnagram("rat", "car") << endl;
	cout << s.isAnagram("anagram", "nagaram") << endl;

	return 0;
}