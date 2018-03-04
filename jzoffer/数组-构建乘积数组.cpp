#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> ans;
        int n = A.size();
        for (int j = 0; j < n; ++j)
        {
            int temp = 1;
            for (int i = 0; i < n; ++i)
            {
                if (i != j)
                {
                    temp *= A[i];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};