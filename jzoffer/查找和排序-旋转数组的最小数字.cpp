#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArrayBF(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
        {
            return 0;
        }
        for (auto iter = rotateArray.begin(); iter + 1 < rotateArray.end(); ++iter)
        {
            if (*iter > *(iter + 1))
                return *(iter + 1);
        }
        return rotateArray[0];
    }
    //二分查找与顺序查找
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if (n == 0)
            return 0;
        int left = 0;
        int right = n - 1;
        int mid = left;

        while (rotateArray[left] >= rotateArray[right])
        {
            if (right - left == 1)
            {
                mid = right;
                break;
            }
            mid = left + (right - left) / 2;
            if (rotateArray[left] == rotateArray[right] &&
                rotateArray[left] == rotateArray[mid])
            {
                for (int i = left; i < right + 1; ++i)
                {
                    if (rotateArray[mid] > rotateArray[i])
                    {
                        mid = i;
                    }
                }
                break;
            }
            if (rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            else if (rotateArray[mid] <= rotateArray[right])
            {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};