#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
            return -1;
        int ret_value = root->val;
        int layer_count = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (q.empty() == false)
        {
            int layer_count_temp = 0;
            for (int i = 0; i < layer_count; ++i)
            {
                TreeNode * temp = q.front();
                q.pop();
                if (i == 0)
                {
                    ret_value = temp->val;
                }
                if (temp->left != nullptr)
                {
                    ++layer_count_temp;
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    ++layer_count_temp;
                    q.push(temp->right);
                }
            }
            layer_count = layer_count_temp;
        }
        return ret_value;
    }
};