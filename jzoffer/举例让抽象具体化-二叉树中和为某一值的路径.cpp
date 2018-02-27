#include <vector>

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find_path(root, expectNumber, vector<int>(), 0);
        return all_path;
    }
private:
    void find_path(TreeNode * node, int expectNumber, vector<int> v, int currentSum) {
        if (node == nullptr)
        {
            return;
        }
        bool is_leaf = (node->left == nullptr) && (node->right == nullptr);
        currentSum += node->val;
        if (currentSum == expectNumber && is_leaf)
        {
            v.push_back(node->val);
            all_path.push_back(v);
            return;
        }
        if (currentSum > expectNumber)
        {
            return;
        }
        v.push_back(node->val);
        if (node->left != nullptr)
            find_path(node->left, expectNumber, v, currentSum);
        if (node->right != nullptr)
            find_path(node->right, expectNumber, v, currentSum);
    }
    vector<vector<int>> all_path;
};