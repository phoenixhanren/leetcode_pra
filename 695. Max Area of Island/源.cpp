#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		this->grid = grid;
		m = grid.size();
		if (m == 0)
			return 0;
		n = grid[0].size();
		visited.resize(m);
		for (int i = 0; i != m; ++i)
		{
			visited[i] = vector<bool>(n, false);
		}
		int max_sum = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 1)
				{
					int temp_sum = maxSum(i, j);
					max_sum = temp_sum > max_sum ? temp_sum : max_sum;
				}
			}
		}
		return max_sum;
	}
private:
	int m, n;
	vector<vector<int>> grid;
	vector<vector<bool>> visited;
	int maxSum(int r, int c) {
		if (r >= m || r < 0 || c >= n || c < 0)
			return 0;
		if (visited[r][c] || grid[r][c] == 0)
			return 0;
		visited[r][c] = true;
		int ret = 1 + maxSum(r - 1, c) + maxSum(r + 1, c) +
			maxSum(r, c - 1) + maxSum(r, c + 1);
		//visited[r][c] = false;
		return ret;
	}

};