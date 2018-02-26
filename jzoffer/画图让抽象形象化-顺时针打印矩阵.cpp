#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m = matrix.size();
        if (m == 0)
            return vector<int>();
        int n = matrix[0].size();
        int left = 0, right = n ;
        int top = 0, bottom = m ;
        vector<int> ans;
        while (left < right && top < bottom)
        {
            for (int i = left; i < right; ++i)
            {
                ans.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i < bottom; ++i)
            {
                ans.push_back(matrix[i][right - 1]);
            }
            if (top + 1 != bottom)
            {
                for (int i = right - 2; i >= left; --i)
                {
                    ans.push_back(matrix[bottom - 1][i]);
                }
            }
            if (left + 1 != right)
            {
                for (int i = bottom - 2; i >= top + 1; --i)
                {
                    ans.push_back(matrix[i][left]);
                }
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }
        return ans;
    }
};