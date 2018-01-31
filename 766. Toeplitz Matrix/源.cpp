#include <vector>

using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int m = matrix.size(); 
		int n = matrix[0].size();

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;
			}
		}
		return true;
	}

	bool isToeplitzMatrixSilly(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		vector<vector<bool>> visited(m);
		for (int i = 0; i < m; ++i)
		{
			vector<bool> temp(n, false);
			visited[i] = temp;
		}
		
		for (int i = 0; i < m; ++i)
		{
			//int num = matrix[i][0];
			for (int j = 0; j < n ; ++j)
			{
				int num = matrix[i][j];
				if (visited[i][j] == false)
				{
					visited[i][j] = true;
					for (int k = 1; k + i < m && k + j < n; ++k)
					{
						if (num != matrix[k + i][k + j])
						{
							return false;
						}
						visited[k + i][k + j] = true;
					}
				}
				else
				{
					break;
				}
			}
		}
		return true;
	}
};