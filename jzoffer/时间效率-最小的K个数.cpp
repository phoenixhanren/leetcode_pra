#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size())
            return vector<int>();

        vector<int> ret(input.begin(), input.end());
        sort(ret.begin(), ret.end());
        ret.resize(k);
        return ret;        
    }
};