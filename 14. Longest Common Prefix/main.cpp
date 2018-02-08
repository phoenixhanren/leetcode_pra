#include <vector>
#include <string>
//#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //stringstream ss;
        //ss << "";
        if (strs.size() == 0)
            return "";

        string ans("");
        for (int i = 0; i < strs[0].length(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i >= strs[j].length())
                    return ans;
                if (strs[j][i] != strs[0][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> v;
    cout << s.longestCommonPrefix(v) << endl;
}