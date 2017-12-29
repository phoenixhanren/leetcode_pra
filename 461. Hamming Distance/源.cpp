#include <iostream>
using namespace std;

class Solution {
public:
	int hammingDistanceSilly(int x, int y) {
		int mask = 0x80000000;
		int mask_get = 0x00000001;
		int ans = 0;
		for (int i = 0; i != 32; ++i)
		{
			int temp_x = ((x & mask) >> 31) & mask_get;
			int temp_y = ((y & mask) >> 31) & mask_get;

			ans += (temp_x ^ temp_y);
		
			x = x << 1;
			y = y << 1;
		}
		return ans;
	}

	// Conclusion: n & (n - 1) converts the right most 1 to 0
	int hammingDistance(int x, int y) {
		int count = 0;
		int n = x ^ y;

		while (n)
		{
			++count;
			n &= n - 1;
		}
		return count;
	}
};

int main()
{
	Solution s;

	cout << s.hammingDistance(1, 4) << endl;

	return 0;
}