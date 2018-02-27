#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        int root = sequence[n - 1];

        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n - 1; ++i)
        {
            if (sequence[i] < root)
            {
                left.push_back(sequence[i]);
            }
            else
            {
                break;
            }
        }

        for (int i = left.size(); i < n - 1; ++i)
        {
            if (sequence[i] < root)
            {
                return false;
            }
            right.push_back(sequence[i]);
        }
        return (left.size() == 0 || VerifySquenceOfBST(left)) && (right.size() == 0 || VerifySquenceOfBST(right));

    }
};