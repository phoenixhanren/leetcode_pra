#include <vector>

using namespace std;

class Solution {
public:
//idea 现在1的位等于最后一位是否为一加上非最后一位一的个数
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        int mask = 0x01;

        for (int i = 2; i <= num; ++i)
        {
            dp[i] = dp[i >> 1] + (i & mask);
        }
        return dp;
    }

//idea from leetcode
//i&(i-1) drops the lowest set bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100,
// the number of “1” in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1. 
    vector<int> countBitsL(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }  
};