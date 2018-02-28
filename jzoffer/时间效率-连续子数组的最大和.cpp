#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int total_max = array[0];
        int curr_max = array[0];
        for (int i = 1; i < array.size(); ++i)
        {
            if (curr_max < 0)
            {
                curr_max = 0;
            }
            curr_max += array[i];
            total_max = total_max > curr_max ? total_max : curr_max;
        }
        return total_max;
    }
};