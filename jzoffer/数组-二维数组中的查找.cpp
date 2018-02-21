#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        if (row == 0)
            return false;
        int col = array[0].size();

        for (int i = 0; i < row; ++i)
        {
            if (binary_search(array[i].begin(), array[i].end(), target))
            {
                return true;
            }
        }
        return false;
    }
    //从左下角元素往上查找，右边元素是比这个元素大，上边是的元素比这个元素小。
    //于是，target比这个元素小就往上找，比这个元素大就往右找。
    //如果出了边界，则说明二维数组中不存在target元素。
    bool FindI(int target, vector<vector<int> > array)  {
        int row = array.size();
        if (row == 0)
            return false;
        int col = array[0].size();
        int i = row - 1;
        int j = 0;
        while (i < row && j < col && i >= 0 && j >= 0)
        {
            if (array[i][j] == target)
                return true;
            if (array[i][j] > target)
            {
                --i;
            }
            else
            {
                ++j;
            }
        }
        return false;
    }
};