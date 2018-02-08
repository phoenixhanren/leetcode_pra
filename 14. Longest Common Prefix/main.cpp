#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stringstream ss;
        ss << "";
        for (int i = 0; i < strs[0].length(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i >= strs[j].length())
                    return ss.str();
                if (strs[j][i] != strs[0][i])
                    return ss.str();
            }
            ss << strs[0][i];
        }
        return ss.str();
    }
};

int main()
{
    Solution s;

}