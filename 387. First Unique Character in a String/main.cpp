#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> c_map;

        for (char c : s)
        {
            ++c_map[c];
        }

        for (int i = 0; i != s.length(); ++i)
        {
            if (c_map[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
    int firstUniqCharfspointer(string s) {
        int len = s.length();
        if (len == 0)
            return -1;
        if (len == 1)
            return 0;
        int slow_p = 0;
        int fast_p = 1;
        int c_count[26];
        for (int i = 0; i < 26; ++i)
        {
            c_count[i] = 0;
        }

        ++c_count[s[slow_p] - 'a'];

        while (fast_p < len)
        {
            ++c_count[s[fast_p] - 'a'];

            while (slow_p < len && c_count[s[slow_p] - 'a'] > 1)
                ++slow_p;
            if (slow_p >= len)
                return -1;
            if (c_count[s[slow_p] - 'a'] == 0)
            {
                ++c_count[s[slow_p] - 'a'];
                fast_p = slow_p;
            }
            ++fast_p;
        }
        return slow_p;

    }
};