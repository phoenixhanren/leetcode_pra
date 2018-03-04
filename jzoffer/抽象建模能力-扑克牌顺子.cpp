#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() == 0)
            return false;
        sort(numbers.begin(), numbers.end());
        int zero_count = numbers[0] == 0 ? 1 : 0;
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (numbers[i] == 0)
                ++zero_count;
            else if (numbers[i - 1] == 0 || numbers[i] - numbers[i - 1] == 1)
            {
                continue;
            }
            else
            {
                int diff = numbers[i] - numbers[i - 1] - 1;
                if (diff < 0)
                {
                    return false;
                }
                else if (diff <= zero_count)
                {
                    zero_count -= diff;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};