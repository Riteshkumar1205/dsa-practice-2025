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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end)
            return {nullptr};  // empty tree

        vector<TreeNode*> result;

        // Pick each number as root
        for (int root = start; root <= end; root++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = generateTrees(start, root - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = generateTrees(root + 1, end);

            // Combine all left and right subtree pairs
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
        return generateTrees(1, n);
    }
};
