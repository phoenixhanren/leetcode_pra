#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        TreeNode * curr = new TreeNode(pre[0]);
        auto iter = vin.begin();
        for (; iter != vin.end(); ++iter)
        {
            if (*iter == pre[0])
                break;
        }
        vector<int> left_vin(vin.begin(), iter);
        vector<int> right_vin(iter + 1, vin.end());
        vector<int> left_pre;
        vector<int> right_pre;
        int i = 1;
        for (int j = 0;j < left_vin.size(); ++j, ++i)
        {
            left_pre.push_back(pre[i]);
        }
        for (int j = 0; j < right_vin.size(); ++j, ++i)
        {
            right_pre.push_back(pre[i]);
        }
        curr->left = reConstructBinaryTree(left_pre, left_vin);
        curr->right = reConstructBinaryTree(right_pre, right_vin);
        return curr;
    }
};