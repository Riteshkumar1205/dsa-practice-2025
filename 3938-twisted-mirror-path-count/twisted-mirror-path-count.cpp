class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<pair<int, int>>>> jump(
            m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2}))
        );

        auto get_target = [&](auto& self, int r, int c, int dir) -> pair<int, int> {
            if (r >= m || c >= n) return {-1, -1};
            if (grid[r][c] == 0) return {r, c};

            if (jump[r][c][dir].first != -2) {
                return jump[r][c][dir];
            }

            pair<int, int> res;
            if (dir == 0) {
                res = self(self, r + 1, c, 1);
            } else {
                res = self(self, r, c + 1, 0);
            }

            return jump[r][c][dir] = res;
        };

        // dp[r][c] = number of paths to empty cell (r, c)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0 || grid[r][c] == 1) continue;

                long long ways = dp[r][c];

                // 1. Move Right (dir = 0) into (r, c + 1)
                auto [tr1, tc1] = get_target(get_target, r, c + 1, 0);
                if (tr1 != -1) {
                    dp[tr1][tc1] = (dp[tr1][tc1] + ways) % MOD;
                }

                // 2. Move Down (dir = 1) into (r + 1, c)
                auto [tr2, tc2] = get_target(get_target, r + 1, c, 1);
                if (tr2 != -1) {
                    dp[tr2][tc2] = (dp[tr2][tc2] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};