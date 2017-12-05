#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		if (bits.size() == 0)
			return false;
		if (bits.size() == 1)
			return true;
		if (bits[0] == 0)
		{
			vector<int> temp(bits.begin() + 1, bits.end());
			return isOneBitCharacter(temp);
		}
		if (bits[0] == 1)
		{
			vector<int> temp(bits.begin() + 2, bits.end());
			return isOneBitCharacter(temp);
		}
		return false;
	}

	bool isOneBitCharacterIter(vector<int> & bits) {
		
		int ones = 0;

		auto iter = bits.rbegin();
		iter += 1;

		for (; iter != bits.rend() && *iter != 0; ++iter)
		{
			++ones;
		}
		if (ones % 2 != 0)
		{
			return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<int> test_case1({ 1, 0, 0 });
	vector<int> test_case2({ 1, 1, 1, 0 });
	vector<int> test_case3({ 1, 0, 0 });
	cout << s.isOneBitCharacter(test_case1) << endl;
	cout << s.isOneBitCharacter(test_case2) << endl;
	cout << s.isOneBitCharacterIter(test_case3) << endl;
	return 0;
}