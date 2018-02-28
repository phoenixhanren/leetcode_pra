#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str_num;
        for (int i = 0; i < numbers.size(); ++i)
        {
            str_num.push_back(to_string(numbers[i]));
        }
        sort(str_num.begin(), str_num.end(), compare);
        stringstream ss;
        for (int i = 0 ; i < str_num.size(); ++i)
        {
            ss << str_num[i];
        }
        return ss.str();
    }
private:
    static bool compare(const string & left, const string & right) {
		stringstream ss;
		string str_1, str_2;
		ss << left << right;
		ss >> str_1;
		ss.clear();
		ss << right << left;
		ss >> str_2;
		return str_1 < str_2;
    }
};