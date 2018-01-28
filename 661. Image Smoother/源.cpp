#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int len = M.size();
		int wid = M[0].size();

		vector<vector<int>> ans(len);
		for (int i = 0; i < len; ++i)
		{
			vector<int> temp(wid, 0);
			ans[i] = temp;
		}

		
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < wid; ++j)
			{
				int count = 1;
				int m11 = 0, m12 = 0, m13 = 0;
				int m21 = 0, m22 = M[i][j], m23 = 0;
				int m31 = 0, m32 = 0, m33 = 0;

				if (i - 1 >= 0)
				{
					if (j - 1 >= 0)
					{
						m11 = M[i - 1][j - 1];
						++count;
					}
					m12 = M[i - 1][j];
					++count;
					if (j + 1 < wid)
					{
						m13 = M[i - 1][j + 1];
						++count;
					}
				}

				if (j - 1 >= 0)
				{
					m21 = M[i][j - 1];
					++count;
				}
				if (j + 1 < wid)
				{
					m23 = M[i][j + 1];
					++count;
				}

				if (i + 1 < len)
				{
					if (j - 1 >= 0)
					{
						m31 = M[i + 1][j - 1];
						++count;
					}
					m32 = M[i + 1][j];
					++count;
					if (j + 1 < wid)
					{
						m33 = M[i + 1][j + 1];
						++count;
					}
				}
				ans[i][j] = (m11 + m12 + m13
					+ m21 + m22 + m23
					+ m31 + m32 + m33) / count;

			}
		}
		return ans;

	}
};

int main()
{
	Solution s;
	vector<vector<int>> ts1;
	vector<int> line_1 { 1, 1, 1 };
	vector<int> line_2 { 1, 0, 1 };
	vector<int> line_3{ 1, 1, 1 };
	ts1.push_back(line_1);
	ts1.push_back(line_2);
	ts1.push_back(line_3);
	s.imageSmoother(ts1);




}