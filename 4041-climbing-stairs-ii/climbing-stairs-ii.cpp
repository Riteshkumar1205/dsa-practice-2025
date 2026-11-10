class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        
        dp[0] = 0;
        
        for (int j = 1; j <= n; ++j) {
            int min_cost = 2e9; 
            
            for (int step = 1; step <= 3; ++step) {
                int i = j - step;
                if (i >= 0) {
                    int jump_cost = costs[j - 1] + (j - i) * (j - i);
                    min_cost = min(min_cost, dp[i] + jump_cost);
                }
            }
            dp[j] = min_cost;
        }
        
        return dp[n];
    }
};