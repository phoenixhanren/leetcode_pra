#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> n_map;
        int n = numbers.size();
        for (int i = 0; i != n; ++i)
        {
            ++n_map[numbers[i]];
        }
        int major = 0;
        int half_n = n / 2;
        for (int i = 0; i != n; ++i)
        {
            if (n_map[numbers[i]] > half_n)
            {
                major = numbers[i];
                break;
            }
        }
        return major;
    }
};