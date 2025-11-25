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
    vector<int> inorderList;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderList.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* buildBalanced(int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(inorderList[mid]);

        root->left = buildBalanced(start, mid - 1);
        root->right = buildBalanced(mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);  
        return buildBalanced(0, inorderList.size() - 1);
    }
};
