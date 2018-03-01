#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> c_map;
        for (int i = 0; i != str.length(); ++i)
        {
            ++c_map[str[i]];
        }
        for (int i = 0; i != str.length(); ++i)
        {
           if (c_map[str[i]] == 1)
            return i;
        }    
        return -1;    
    }
};