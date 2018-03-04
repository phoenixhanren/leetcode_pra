#include <string>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int n = str.length();
        if (n == 0)
        {
            return 0;
        }

        int ans = 0;
        int i = 0;
        bool is_nav = false;
        if (str[i] == '+')
        {
            i = 1;
        }
        else if (str[i] == '-')
        {
            i = 1;
            is_nav = true;
        }
        else if (isdigit(str[i]))
        {
            ans = str[i] - '0';
            i = 1;
        }
        for (; i < n; ++i)
        {
            if (isdigit(str[i]))
            {
                ans *= 10;
                ans += (str[i] - '0');
            }
            else
            {
                return 0;
            }
        }
        return is_nav ? -ans : ans;
    }
};