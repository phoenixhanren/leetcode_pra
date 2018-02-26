#include <vector>
#include <queue>

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr)
            return false;
        if (pRoot2 == nullptr)
            return false;
        bool ans = false;
        if (pRoot1->val == pRoot2->val)
        {
            ans = isSub(pRoot1, pRoot2);
        }
        if (ans == false)
        {
            ans = HasSubtree(pRoot1->left, pRoot2);
            if (ans == false)
                ans = HasSubtree(pRoot1->right, pRoot2);
        }
        return ans;
    }

    bool isSub(TreeNode * root1, TreeNode * root2)
    {
        if (root2 == nullptr)
            return true;
        if (root1 == nullptr)
            return false;
        if (root1->val == root2->val)
        {
            return isSub(root1->left, root2->left) && isSub(root1->right, root2->right);
        }
        else
        {
            return false;
        }
    }
};