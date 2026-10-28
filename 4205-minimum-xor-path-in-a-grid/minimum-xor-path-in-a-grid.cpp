class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<bitset<1024>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bitset<1024> reach;
                
                if (i == 0 && j == 0) {
                    reach.set(0);
                } else {
                    if (i > 0) {
                        reach |= dp[j];
                    }
                    if (j > 0) {
                        reach |= dp[j - 1];
                    }
                }
                
                dp[j].reset();
                int val = grid[i][j];
                for (int x = 0; x < 1024; ++x) {
                    if (reach.test(x)) {
                        dp[j].set(x ^ val);
                    }
                }
            }
        }
        
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};