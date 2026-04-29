using ll = long long;

static ll colSum[100][101];   // prefix sum per column (1-indexed rows)
static ll dp[100][101][2];    // dp[col][black_count][state]
static int n;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) return 0;

        // build column-wise prefix sum
        for (int j = 0; j < n; j++) {
            colSum[j][0] = 0;
            for (int i = 0; i < n; i++) {
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }

        // clear dp
        for (int j = 0; j < n; j++) {
            for (int b = 0; b <= n; b++) {
                dp[j][b][0] = dp[j][b][1] = 0;
            }
        }

        // iterate columns
        for (int j = 1; j < n; j++) {
            for (int b0 = 0; b0 <= n; b0++) {
                ll prev0 = dp[j - 1][b0][0];
                ll prev1 = dp[j - 1][b0][1];

                for (int b1 = 0; b1 <= n; b1++) {

                    bool bigger = (b1 > b0);

                    // gain from previous column (j-1)
                    ll gainPrev = bigger ? 
                        (colSum[j - 1][b1] - colSum[j - 1][b0]) : 0;

                    // gain from current column (j)
                    ll gainCur = (!bigger) ? 
                        (colSum[j][b0] - colSum[j][b1]) : 0;

                    // state 0 → current column not finalized
                    dp[j][b1][0] = max(
                        dp[j][b1][0],
                        max(prev0 + gainPrev, prev1)
                    );

                    // state 1 → current column finalized
                    dp[j][b1][1] = max(
                        dp[j][b1][1],
                        gainCur + max(prev1, prev0 + gainPrev)
                    );
                }
            }
        }

        // final answer → last column must be finalized
        ll ans = 0;
        for (int b = 0; b <= n; b++) {
            ans = max(ans, dp[n - 1][b][1]);
        }

        return ans;
    }
};

// fast io
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();