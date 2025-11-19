/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + std::max(leftHeight, rightHeight);
    }
};
