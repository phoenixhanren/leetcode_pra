#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0)
            return 0;
        int last = last_k(data, k); 
        int first = first_k(data, k);
        if (last == -1 && first == -1)
            return 0;
        return last - first + 1;
    }
private:
    int first_k(vector<int>& data, int k) {
        int left = 0;
        int right = data.size() - 1;
        int mid ;
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (data[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }

            //mid = (right + left) / 2;
        }
        if (data[right] == k)
            return right;
        return -1;
    }
    int last_k(vector<int>& data, int k) {
        int left = 0;
        int right = data.size() - 1;
        int mid;
        while (left < right)
        {
            mid = left + ((right - left + 1) >> 1);
            if (data[mid] <= k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (data[left] == k)
            return left;
        return -1;
    }
    
};