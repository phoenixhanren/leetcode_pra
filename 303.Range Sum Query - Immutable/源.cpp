#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		if (nums.size() == 0)
			mem.push_back(0);
		else
		{
			mem.push_back(nums[0]);
			for (int i = 1; i != nums.size(); ++i)
			{
				mem.push_back(nums[i] + mem[i - 1]);
			}
		}

		//int size = nums.size();
		//for (int i = 0; i != size; ++i)
		//{
		//	mem.push_back(vector<int>(size, INT_MAX));
		//	mem[i][i] = nums[i];
		//}
		////for (int i = 0; i != size; ++i)
		////{
		////	mem[i][i] = nums[i];
		////}
		//for (int i = 1; i < size; ++i)
		//{
		//	for (int j = i - 1; j >= 0; --j)
		//	{
		//		mem[i][j] = mem[i][i] + mem[i - 1][j];
		//	}
		//}

		
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return mem[j];
		return mem[j] - mem[i - 1];
		//return mem[j][i];
		//if (mem[i][j] != INT_MAX)
		//{
		//	return mem[i][j];
		//}
		//else
		//{
		//	mem[i][j] = sumRange(j, j) + sumRange(i, j - 1);
		//	return mem[i][j];
		//}
	}

private:
	//vector<vector<int>> mem;
	//vector<int> nums;
	vector<int> mem;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/

int main()
{
	vector<int> nums({ -2, 0, 3, -5, 2, -1 });
	NumArray obj(nums);

	cout << obj.sumRange(0, 2) << endl;
	cout << obj.sumRange(2, 5) << endl;
	cout << obj.sumRange(0, 5) << endl;

	return 0;

}