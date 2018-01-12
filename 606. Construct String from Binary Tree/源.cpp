#include <iostream>
#include <string>
#include <sstream>

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
	string tree2str(TreeNode* t) {
		if (t == nullptr)
			return "";
		stringstream ss;
		ss << t->val;

		if (t->left != nullptr)
		{
			ss << "(";
			ss << tree2str(t->left);
			ss << ")";
		}
		if (t->right != nullptr)
		{
			if (t->left == nullptr)
				ss << "()";
			ss << "(";
			ss << tree2str(t->right);
			ss << ")";
		}

		//ss << t->val;
		//ss << "(";
		//ss << tree2str(t->left);
		//ss << ")(";
		//ss << tree2str(t->right);
		//ss << ")";
		return ss.str();
	}
};



int main()
{
	
}