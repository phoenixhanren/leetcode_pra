#include <iostream>

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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		return recTree(root, 0, sum);
	}

	bool recTree(TreeNode * root, int parent_sum, int sum) {
		int temp_sum = parent_sum + root->val;

		if (root->left == nullptr && root->right == nullptr)
			return temp_sum == sum;

		//if (temp_sum > sum)
		//	return false;

		bool left = false;
		if (root->left != nullptr)
		{
			left = recTree(root->left, temp_sum, sum);
		}

		bool right = false;
		if (root->right != nullptr)
		{
			right = recTree(root->right, temp_sum, sum);
		}

		return left || right;
	}

	bool hasPathSum1(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (root->left == nullptr && root->right == nullptr)
			return root->val == sum;
		return hasPathSum1(root->left, sum - root->val) ||
			hasPathSum1(root->right, sum - root->val);
	}

};

int main()
{
	TreeNode head(5);
	TreeNode leftOne(4);
	TreeNode rightOne(8);
	TreeNode leftleftSecond(11);
	TreeNode rightleftSecond(13);
	TreeNode rightrightSecond(4);
	TreeNode leftleftThird(7);
	TreeNode leftrightThird(2);
	TreeNode rightrightThird(1);

	leftleftSecond.left = &leftleftThird;
	leftleftSecond.right = &leftrightThird;
	leftOne.left = &leftleftSecond;
	head.left = &leftOne;
	head.right = &rightOne;
	rightOne.left = &rightleftSecond;
	rightOne.right = &rightrightSecond;
	rightrightSecond.right = &rightrightThird;

	Solution s;

	cout << s.hasPathSum(&head, 22) << endl;
	return 0;
}