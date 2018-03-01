#include <math>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return isBalanced(pRoot, depth);
    }
    bool IsBalanced_SolutionRec(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return true;
        if (abs(depthRec(pRoot->left) - depthRec(pRoot->right)) > 1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
private:
    bool isBalanced(TreeNode * node, int & depth)
    {
        if (node == nullptr)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (isBalanced(node->left, left) && isBalanced(node->right, right))
        {
            if (abs(left - right) > 1)
                return false;
            depth = max(left, right) + 1;
            return true;
        }
        return false;
    }
    int depthRec(TreeNode * node) {
        if (node == nullptr)
            return 0;
        return max(depthRec(node->left), depthRec(node->right)) + 1;
    }
};