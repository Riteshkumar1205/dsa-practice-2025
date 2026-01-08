class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int product = nums1[i] * nums2[j];
                int take = product;
                if (i > 0 && j > 0) take = max(take, dp[i-1][j-1] + product);
                
                int skip1 = (i > 0) ? dp[i-1][j] : INT_MIN;
                int skip2 = (j > 0) ? dp[i][j-1] : INT_MIN;
                
                dp[i][j] = max({take, skip1, skip2});
            }
        }
        
        return dp[n1-1][n2-1];
    }
};