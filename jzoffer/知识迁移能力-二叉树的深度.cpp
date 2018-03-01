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
    int TreeDepth(TreeNode* pRoot) {
        return depthRec(pRoot);
    }

private:

    int depthRec(TreeNode * node) {
        if (node == nullptr)
            return 0;
        return max(depthRec(node->left), depthRec(node->right)) + 1;
    }
    
};