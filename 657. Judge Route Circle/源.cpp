#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int horizon = 0;
		int vertical = 0;
		
		for (int i = 0; i != moves.length(); ++i)
		{
			switch (moves[i])
			{
			case 'R':
				++horizon;
				break;
			case 'L':
				--horizon;
				break;
			case 'U':
				++vertical;
				break;
			case 'D':
				--vertical;
				break;
			default:
				break;
			}
		}
		return horizon == 0 && vertical == 0;
	}
};