#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n <= 2)
            return 0;
        vector<int> arit = {A[0], A[1]};
        int sub = A[1] - A[0];
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (A[i] - arit[arit.size() - 1] == sub)
            {
                arit.push_back(A[i]);
            }
            else
            {
                for (int j = arit.size() - 2; j >= 1; --j)
                {
                    count += j;
                }
                int temp = arit[arit.size() - 1];
                arit.clear();
                arit.push_back(temp);
                arit.push_back(A[i]);
                sub = arit[1] - arit[0];
            }
        }
        for (int j = arit.size() - 2; j >= 1; --j)
        {
            count += j;
        }
        return count;
    }

// dp[i] means the number of arithmetic slices ending with A[i]
 // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
  // equals to:
  //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
  //      +
  //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
  // it is how dp[i] = dp[i-1] + 1 comes

    int numberOfArithmeticSlicesL(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        if (n <= 2)
            return 0;
        if (A[2] - A[1] == A[1] - A[0])
            dp[2] = 1;
        int result = dp[2];
        for (int i = 3; i < n; ++i)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
            result += dp[i];
        }
        return result;
    }
};