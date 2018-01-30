#include <vector>

using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		vector<int> temp_flowerbed(flowerbed.begin(), flowerbed.end());

		int s = temp_flowerbed.size();
		int count = 0;
		if (s == 1 && temp_flowerbed[0] == 0)
		{
			++count;
		}
		else
		{
			if (temp_flowerbed[0] == 0 && temp_flowerbed[1] == 0)
			{
				++count;
				temp_flowerbed[0] = 1;
			}
		}

		for (int i = 1; i < s - 1; ++i)
		{
			if (temp_flowerbed[i] == 0)
			{
				if (temp_flowerbed[i - 1] == 0 && temp_flowerbed[i + 1] == 0)
				{
					temp_flowerbed[i] = 1;
					++count;
				}
			}
		}
		if (temp_flowerbed[s - 1] == 0)
		{
			if (s - 2 >= 0 && temp_flowerbed[s - 2] == 0)
			{
				temp_flowerbed[s - 1] = 1;
				++count;
			}
		}
		return count >= n;



	}
};