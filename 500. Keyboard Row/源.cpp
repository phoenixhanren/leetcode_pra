#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> c_map;
		string first_line = "qwertyuiop";
		string second_line = "asdfghjkl";
		string third_line = "zxcvbnm";
		add_to_map(first_line, 1, c_map);
		add_to_map(second_line, 2, c_map);
		add_to_map(third_line, 3, c_map);

		vector<string> ans;
		for (int i = 0; i != words.size(); ++i)
		{
			if (words[i].length() == 0)
			{
				ans.push_back(words[i]);
			}
			else
			{
				int last_val = c_map[tolower(words[i][0])];
				bool one_row = true;
				
				for (int j = 1; j < words[i].length(); ++j)
				{
					if (last_val != c_map[tolower(words[i][j])])
					{
						one_row = false;
						break;
					}
				}
				if (one_row)
				{
					ans.push_back(words[i]);
				}
			}	
		}
		return ans;

	}

	void add_to_map(string key, int value, unordered_map<char, int> &c_map)
	{
		for (int i = 0; i != key.length(); ++i)
		{
			c_map[key[i]] = value;
		}
	}

};

int main()
{
	Solution s;
	vector<string> test_case1({"Hello","Alaska","Dad","Peace"});

	vector<string> ret = s.findWords(test_case1);
	return 0;

}