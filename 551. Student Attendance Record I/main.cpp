#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a_count = 0;
        char last_c = ' ';
        char last_last_c = ' ';

        for (char c : s)
        {
            if (c == 'A')
            {
                ++a_count;
                if (a_count > 1)
                {
                    return false;
                }
            }
            else if (c == 'L')
            {
                if (last_c == c && last_last_c == c)
                {
                    return false;
                }
            }
            last_last_c = last_c;
            last_c = c;
        }
        return true;
    }
};