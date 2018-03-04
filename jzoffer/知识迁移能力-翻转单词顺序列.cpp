#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        for (auto iter = str.begin(), iter_end = str.begin(); iter != str.end();)
        {
            if (*iter == ' ')
            {
                ++iter;
                ++iter_end;
            }
            else if (iter_end == str.end() || *iter_end == ' ')
            {
                reverse(iter, iter_end);
                iter = iter_end;
            }
            else
            {
                ++iter_end;
            }
        }
        return str;
    }
};