#include <list>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;

        list<int> child;
        for (int i = 0; i < n; ++i)
        {
            child.push_back(i);
        }
        auto iter = child.begin();
        while (child.size() != 1)
        {
            int count = 1;
            while (count < m)
            {
                ++iter;
                if (iter == child.end())
                    iter = child.begin();
                ++count;
            }
            auto iter_temp = iter;
            ++iter;
            if (iter == child.end())
                iter = child.begin();
            child.erase(iter_temp);
        }
        return *iter;
    }
    //f(n, m) = 0        n==1
    //        = [f(n - 1, m) + m] % n    n > 1
    int LastRemaining_SolutionM(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};