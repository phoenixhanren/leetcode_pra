#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int iter = 0;
        int len = str.length();
        if (len <= n)
            return str;

        for (int i = 0; i < n; ++i)
        {
            if (iter == len)
            {
                iter = 0;
            }
            else
            {
                ++iter;
            }
        }
        int end_iter = iter;
        if (iter == len)
            return str;
        stringstream ss;
        ss << str[iter];
        for(++iter; iter != end_iter;)
        {
            if (iter == len)
            {
                iter = 0;
            }
            else
            {
                ss << str[iter];
            }
        }
        return ss.str();
    }
    string LeftRotateStringRev(string str, int n) {
        int len = str.length();
        if (n >= len)
        {
            n %= len;
        }
        reverse(str.begin(), str.begin() + n);
        reverse(str.begin() + n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};