#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;

		queue<TreeNode *> i;
		//queue<TreeNode *> j;
		i.push(root);
		while (!i.empty())
		{
			queue<TreeNode *> temp;
			vector<int> vals;
			bool last_layer = true;
			while (!i.empty())
			{
				TreeNode * node = i.front();
				if (node == nullptr)
				{
					vals.push_back(INFINITY);
					temp.push(nullptr);
					temp.push(nullptr);
				}
				else
				{
					last_layer = false;
					vals.push_back(node->val);
					temp.push(node->left);
					temp.push(node->right);
				}
				i.pop();
			}
			if (last_layer)
				break;

			int v_size = vals.size();
			for (int i = 0, j = v_size - 1; i < v_size / 2 && j >= v_size / 2; ++i, --j)
			{
				if (vals[i] != vals[j])
					return false;
			}
			i = temp;
		}
		return true;
	}

	bool isSymmetricOneQueue(TreeNode* root) {
		if (root == nullptr)
			return true;

		queue<TreeNode *> left_half;
		queue<TreeNode *> right_half;
		int size = 1;
		left_half.push(root->left);
		right_half.push(root->right);

		while (!left_half.empty() && !right_half.empty())
		{
			int temp = 0;
			for (int i = 0; i < size; ++i)
			{
				TreeNode * left = left_half.front();
				TreeNode * right = right_half.front();
				left_half.pop();
				right_half.pop();
				if (left == nullptr && right == nullptr)
				{
					continue;
				}
					
				if (left == nullptr || right == nullptr)
					return false;

				if (left->val != right->val)
					return false;

				left_half.push(left->left);
				left_half.push(left->right);
				right_half.push(right->right);
				right_half.push(right->left);
				temp += 2;
			}
			size = temp;
		}
		return true;
	}

	bool isSymmetricRec(TreeNode * root) {
		if (root == nullptr)
			return true;
		return isSym(root->left, root->right);
	}

	bool isSym(TreeNode * left, TreeNode * right) {
		if (left == nullptr || right == nullptr)
			return left == right;
		return (left->val == right->val) && isSym(left->left, right->right)
			&& (isSym(left->right, right->left));
	}
};