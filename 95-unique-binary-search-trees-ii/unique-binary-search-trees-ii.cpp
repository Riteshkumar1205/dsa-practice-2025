/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> generateTree(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> result;

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> leftTrees = generateTree(start, root - 1);
            vector<TreeNode*> rightTrees = generateTree(root + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTree(1, n);
    }
};