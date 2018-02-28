#include <vector>
#include <math>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 0)
            return 0;
        vector<int> mem_single(n + 1, 0);
        vector<int> mem_all(n + 1, 0);
        mem_single[1] = 1;
        mem_all[1] = 1;
        if (n < 10)
            return 1;

        for (int i = 2; i < 10; ++i)
        {
            mem_all[i] = mem_all[i - 1];
        }
        for (int i = 10; i <= n; ++i)
        {
            mem_single[i] = mem_single[i / 10];
            mem_single[i] += (i % 10 == 1 ? 1 : 0);
            mem_all[i] = mem_all[i - 1] + mem_single[i];
        }
        return mem_all[n];       
    }
    int NumberOf1Between1AndN_SolutionA(int n)
    {
        if (n <= 0)
            return 0;
        int high = n;//最高位 
        int low;//最低位
        int curr;//当前位 
        int temp, i = 1;
        int total = 0;
        while (high != 0)
        {
            high = n / pow(10, i);
            temp = n - high * pow(10, i);
            curr = temp / pow(10, i - 1);
            low = temp - curr * pow(10, i - 1);
            if (curr == 1)
            {
                total += high * pow(10, i - 1) + (low > 0 ? low : 0) + 1;
            }
            else if (curr < 1)
            {
                total += high * pow(10, i - 1);
            }
            else
            {
                total += (high + 1) * pow(10, i - 1);
            }
            ++i;
        }
        return total;
    }

};