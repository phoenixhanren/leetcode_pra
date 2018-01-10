#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		//vector<TreeNode *> ret;
		//vector<vector<TreeNode *>> dp(n + 1);
		//dp[0].push_back(nullptr);
		//dp[1].push_back(new TreeNode(1));
		//
		//for (int i = 2; i <= n; ++i)
		//{
		//	for (int root = 1; root <= i; ++root)
		//	{
		//		int left_ind = root - 1;
		//		int right_ind = i - root;
		//	}
		//}
		if (n == 0)
			return vector<TreeNode *>(0);


		return generateTrees(1, n);
	}

	vector<TreeNode*> generateTrees(int s, int e) {
		vector<TreeNode *> ret;
		if (s > e)
		{
			ret.push_back(nullptr);
		}
		else if (s == e)
		{
			ret.push_back(new TreeNode(s));
		}
		else
		{
			for (int i = s; i <= e; ++i)
			{
				vector<TreeNode *> left_tree = generateTrees(s, i - 1);
				vector<TreeNode *> right_tree = generateTrees(i + 1, e);

				for (auto left_iter = left_tree.begin(); left_iter != left_tree.end(); ++left_iter)
				{
					for (auto right_iter = right_tree.begin(); right_iter != right_tree.end(); ++right_iter)
					{
						TreeNode * root = new TreeNode(i);
						root->left = *left_iter;
						root->right = *right_iter;
						ret.push_back(root);
					}
				}
			}

		}

		return ret;

	}

	//TreeNode * clone(TreeNode * const root)
	//{
	//	if (root == nullptr)
	//		return nullptr;
	//	
	//	TreeNode * ret_root = new TreeNode(root->val);
	//	ret_root->left = clone(root->left);
	//	ret_root->right = clone(root->right);
	//	return ret_root;
	//}

};

int main()
{

}
