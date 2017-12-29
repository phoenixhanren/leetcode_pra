class Solution {
public:
	int findComplementSilly(int num) {
		int ans = ~num;
		int bit_count = 0;
		while (num)
		{
			++bit_count;
			num >>= 1;
		}
		int mask = 0;
		while (bit_count)
		{
			--bit_count;
			mask <<= 1;
			mask += 1;
		}
		ans &= mask;
		return ans;
	}
	int findComplement(int num) {
		int mask = ~0;
		while (num & mask) mask <<= 1;
		return ~num & ~mask;
	}
};