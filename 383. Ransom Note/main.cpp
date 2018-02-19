#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() == 0)
            return true;
        unordered_map<char, int> m_map;
        auto ran_iter = ransomNote.begin();
        auto mag_iter = magazine.begin();

        for (; mag_iter != magazine.end(); ++mag_iter)
        {
            ++m_map[*mag_iter];
        }

        for (; ran_iter != ransomNote.end(); ++ran_iter)
        {
            if (--m_map[*ran_iter] < 0)
            {
                return false;
            }
        }
        return true;
    }
};