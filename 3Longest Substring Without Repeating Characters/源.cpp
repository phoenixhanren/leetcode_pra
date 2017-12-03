/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_set;
using std::string;
using std::max;
using std::unordered_map;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> subset;

		int i = 0;
		int j = 0;
		int ans = 0;

		int len = s.length();

		while (j < len)
		{
			if (subset.find(s[j]) == subset.end())
			{
				subset.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else
			{
				subset.erase(s[i++]);
			}
		}
		return ans;
	}

	int lengthOfLongestSubstring1(string s) {
		/*unordered_set<char> subset;

		int i = 0;
		int j = 0;
		int ans = 0;

		int len = s.length();

		while (j < len)
		{
			if (subset.find(s[j]) == subset.end())
			{
				subset.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else
			{
				subset.clear();
				subset.insert(s[j]);
				i = j;
				++j;
			}
		}*/
		unordered_map<char, int> map;
		int i = 0;
		int j = 0;
		int ans = 0;
		int len = s.length();

		while (j < len)
		{
			/*if (map.find(s[j]) == map.end())
			{
				map[s[j]] = j;
			}
			else
			{
				i = max(i, map[s[j]] + 1);

			}*/
			if (map.find(s[j]) != map.end())
			{
				i = max(i, map[s[j]] + 1);
			}
			map[s[j]] = j;
			++j;
			ans = max(ans, j - i);
		}

		return ans;
	}
};

int main()
{
	string a("abcabcbb");
	string b("bbbbb");
	string c("pwwkew");

	Solution s;
	std::cout << s.lengthOfLongestSubstring1(a) << std::endl;
	std::cout << s.lengthOfLongestSubstring1(b) << std::endl;
	std::cout << s.lengthOfLongestSubstring1(c) << std::endl;

	return 0;
}