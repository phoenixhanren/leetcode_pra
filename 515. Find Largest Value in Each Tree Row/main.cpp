#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        pre_order_travel(root, ret, 0);
        return ret;
    }

private:
    void pre_order_travel(TreeNode * root, vector<int> & ret, int depth)
    {
        if (root == nullptr)
            return;

        int n = ret.size();

        if (depth >= n)
        {
            ret.push_back(root->val);
        }
        else
        {
            ret[depth] = max(ret[depth], root->val);
        }
        pre_order_travel(root->left, ret, depth + 1);
        pre_order_travel(root->right, ret, depth + 1);
    }

};