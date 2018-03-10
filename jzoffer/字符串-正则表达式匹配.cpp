#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
/*
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int str_len = strlen(str);
        int pat_len = strlen(pattern);
        int i, j;
        for (i = 0, j = 0; i < str_len, j < pat_len;)
        {
            if (str[i] == pattern[j])
            {
                ++i, ++j;
            }
            else if (i < str_len && pattern[j] ==  '.')
            {
                ++i, ++j;
            }
            else
            {
                for (; j < pat_len; ++j)
                {
                    if (pattern[j] == '*')
                        break;
                }
                if (j + 1 < pat_len && pattern[j - 1] == pattern[j + 1])
                {
                    swap(pattern[j + 1], pattern[j]);
                    ++j;
                }

                if (j >= pat_len)
                    return false; 
                else if (pattern[j - 1] == str[i] || pattern[j - 1] == '.')
                {
                    ++i;
                }
                else if (pattern[j - 1] != str[i])
                {
                    ++j;
                }
            }
        }
        if (i >= str_len && j >= pat_len)
        {
            return true;
        }
        return false;
    }
};
*/
/*
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int str_len = strlen(str);
        int pat_len = strlen(pattern);

        int i, j;

        for (i = str_len - 1, j = pat_len - 1; i >= 0 && j >= 0; )
        {
            if (str[i] == pattern[j])
            {
                --i, --j;
            }
            else if (i >= 0 && pattern[j] == '.')
            {
                --i, --j;
            }
            else 
            {
                if (pattern[j] != '*')
                    return false;
                if (pattern[j - 1] == str[i] || pattern[j - 1] == '.')
                {
                    --i;
                }
                else
                {
                    j = j - 2;
                }
            }
        }
        if (i < 0 && j < 0)
            return true;
        return false;
    }
};*/



class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;
        return matchRec(str, pattern, 0, 0);
    }

private:
    bool matchRec(char * str, char * pattern, int str_index, int pat_index) {
            int str_len = strlen(str);
            int pat_len = strlen(pattern);

            if (str_len == str_index && pat_len == pat_index)
                return true;
            
            if (str_index != str_len && pat_len == pat_index)
                return false;
            
            if (pat_index + 1 < pat_len && pattern[pat_index + 1] == '*')
            {
                if (str_index != str_len && (pattern[pat_index] == str[str_index] || pattern[pat_index] == '.'))
                {
                    return matchRec(str, pattern, str_index, pat_index + 2)  ||
                        matchRec(str, pattern, str_index + 1, pat_index + 2) ||
                        matchRec(str, pattern, str_index + 1, pat_index);
                }
                else 
                {
                    return matchRec(str, pattern, str_index, pat_index + 2);
                }
            }

            if (str_index != str_len && (pattern[pat_index] == str[str_index] ||
                pattern[pat_index] == '.'))
            {
                return matchRec(str, pattern, str_index + 1, pat_index + 1);
            }
            return false;
        }
};
