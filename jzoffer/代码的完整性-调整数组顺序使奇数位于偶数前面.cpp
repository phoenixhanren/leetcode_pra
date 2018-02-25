#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArrayWrong(vector<int> &array) {
		int n = array.size();
		if (n == 0 || n == 1)
			return;
		int left = 0;
		int right = n - 1;

		while (left < right)
		{
			for (; left < n; ++left)
			{
				if ((array[left] & 0x01) == 0)
					break;
			}
			for (; right >= 0; --right)
			{
				if ((array[right] & 0x01) == 1)
					break;
			}
			if (left < right)
			{
				int temp = array[left];
				array[left] = array[right];
				array[right] = temp;
			}
			//cout << left << " " << right << endl;
		}
		return;
    }
    void reOrderArray(vector<int> &array) {
        vector<int> temp;
        for (int i = 0; i < array.size(); ++i)
        {
            if ((array[i] & 0x01) == 1)
                temp.push_back(array[i]);
        }
        for (int i = 0; i < array.size(); ++i)
        {
            if ((array[i] & 0x01) == 0)
                temp.push_back(array[i]);
        }
        array.erase(array.begin(), array.end());
        for (int i = 0; i < temp.size(); ++i)
        {
            array.push_back(temp[i]);
        }
    }
};