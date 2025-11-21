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
    int total_tilt = 0;  

    int findTilt(TreeNode* root) {
        dfs(root);        
        return total_tilt; 
    }

private:
    int dfs(TreeNode* node) {
        if (!node) return 0; 

        int left_sum = dfs(node->left);   
        int right_sum = dfs(node->right); 

        total_tilt += abs(left_sum - right_sum); 
        return node->val + left_sum + right_sum; 
    }
};
