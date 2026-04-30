class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[j][c] = max score at column j with cost c
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0; // start

        for (int i = 0; i < m; i++) {
            vector<vector<int>> ndp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {

                    // from top
                    if (i > 0 && dp[j][c] != -1) {
                        int val = grid[i][j];
                        int cost = (val == 0 ? 0 : 1);
                        int score = val;

                        int nc = c + cost;
                        if (nc <= k) {
                            ndp[j][nc] = max(ndp[j][nc], dp[j][c] + score);
                        }
                    }

                    // from left
                    if (j > 0 && ndp[j - 1][c] != -1) {
                        int val = grid[i][j];
                        int cost = (val == 0 ? 0 : 1);
                        int score = val;

                        int nc = c + cost;
                        if (nc <= k) {
                            ndp[j][nc] = max(ndp[j][nc], ndp[j - 1][c] + score);
                        }
                    }

                    // start cell
                    if (i == 0 && j == 0 && c == 0) {
                        ndp[0][0] = 0;
                    }
                }
            }

            dp = ndp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans;
    }
};