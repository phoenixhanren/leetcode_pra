#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        auto push_iter = pushV.begin(), pop_iter = popV.begin();
        for (;pop_iter != popV.end(); ++pop_iter)
        {
            if (s.size() == 0 && push_iter != pushV.end())
            {
                s.push(*push_iter);
                ++push_iter;                
            }
            while (s.top() != *pop_iter && push_iter != pushV.end())
            {
                s.push(*push_iter);
                ++push_iter;
            }
            if (s.top() == *pop_iter)
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        if (s.size() != 0 || pop_iter != popV.end())
        {
            return false;
        }
        return true;
    }
};