
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode * last = nullptr;
        doConvert(pRootOfTree, &last);
        TreeNode * head = last;
        while (head != nullptr && head->left != nullptr)
        {
            head = head->left;
        }
        return head;
    }
private:
    void doConvert(TreeNode * node, TreeNode ** last)
    {
        if (node == nullptr)
            return;
        TreeNode * curr = node;

        if (curr->left != nullptr)
            doConvert(curr->left, last);
        
        curr->left = *last;
        if (*last != nullptr)
            (*last)->right = curr;
        
        *last = curr;
        if (curr->right != nullptr)
            doConvert(curr->right, last);
    }
};