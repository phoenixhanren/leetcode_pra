#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        if (n < 2)
            return array;
        
        int left = 0;
        int right = n - 1;
        int curr_sum;
        while ((curr_sum = array[left] + array[right]) != sum && left < n && right >= 0)
        {
            if (curr_sum < sum)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        if (curr_sum == sum)
            return vector<int>{array[left], array[right]};
        return vector<int>();
    }
};