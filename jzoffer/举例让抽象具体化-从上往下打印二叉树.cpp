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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> ret;
        if (root == nullptr)
            return ret;
        q.push(root);
        while (q.empty() == false)
        {
            TreeNode * temp = q.front();
            ret.push_back(temp->val);
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
            q.pop();
        }
        return ret;
    }
};