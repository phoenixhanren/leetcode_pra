#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> ret;

        int small = 1;
        int big = 2;
        int curr_sum;
        for( ; big < sum; ) 
        {
            curr_sum = (small + big) * (big - small + 1) / 2;
            if (curr_sum < sum)
            {
                ++big;
            }
            else  
            {
                if (curr_sum == sum)
                {
                    vector<int> temp;
                    for (int i = small; i <= big; ++i)
                    {
                        temp.push_back(i);
                    }
                    ret.push_back(temp);
                }
                ++small;
            }
        }
        return ret;
    }
};