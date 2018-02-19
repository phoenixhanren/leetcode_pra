#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_length = haystack.length();
        int n_length = needle.length();
        if (n_length > h_length)
            return -1;
        if (n_length == 0 && h_length == 0)
            return 0;
        for (int i = 0; i < h_length && i + n_length <= h_length; ++i)
        {
            if (haystack.substr(i, n_length) == needle)
            {
                return i;
            }
        }
        return -1;        
    }
};