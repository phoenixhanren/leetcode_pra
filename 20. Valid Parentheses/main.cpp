#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            if (*iter == '(' || *iter == '[' || *iter == '{')
            {
                sta.push(*iter);
            }
            else if (*iter == ')')
            {
                if (sta.size() == 0)
                {
                    return false;
                }
                if (sta.top() == '(')
                {
                    sta.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (*iter == ']')
            {
                if (sta.size() == 0)
                {
                    return false;
                }
                if (sta.top() == '[')
                {
                    sta.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (*iter == '}')
            {
                if (sta.size() == 0)
                {
                    return false;
                }
                if (sta.top() == '{')
                {
                    sta.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return sta.size() == 0;
    }
};