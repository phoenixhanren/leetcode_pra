#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> s;
        for (int i = 0; i < data.size(); ++i)
        {
            auto iter = s.find(data[i]);
            if (iter == s.end())
            {
                s.insert(data[i]);
            }
            else
            {
                s.erase(data[i]);
            }
        }
        if (s.size() == 0)
        {
            num1 = num2 = nullptr;
            return;
        }
        if (s.size() == 1)
        {
            *num1 = *s.begin();
            return;
        }
        *num1 = *s.begin();
        *num2 = *(++s.begin());
        return;
    }
};