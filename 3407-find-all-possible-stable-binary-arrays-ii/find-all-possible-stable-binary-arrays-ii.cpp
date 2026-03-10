class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {

        const int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(
            zeros + 1,
            vector<vector<long long>>(ones + 1, vector<long long>(2, 0))
        );

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int i = 0; i <= zeros; i++) {
            for (int j = 0; j <= ones; j++) {

                if (i == 0 && j == 0) continue;

                long long endWithZero = 0;
                long long endWithOne = 0;

                if (j > 0) {
                    endWithZero = dp[i][j-1][1];

                    if (j > 1)
                        endWithZero = (endWithZero + dp[i][j-1][0]) % MOD;

                    if (j > limit)
                        endWithZero = (endWithZero - dp[i][j-1-limit][1] + MOD) % MOD;
                }

                if (i > 0) {
                    endWithOne = dp[i-1][j][0];

                    if (i > 1)
                        endWithOne = (endWithOne + dp[i-1][j][1]) % MOD;

                    if (i > limit)
                        endWithOne = (endWithOne - dp[i-1-limit][j][0] + MOD) % MOD;
                }

                dp[i][j][0] = endWithZero % MOD;
                dp[i][j][1] = endWithOne % MOD;
            }
        }

        return (dp[zeros][ones][0] + dp[zeros][ones][1]) % MOD;
    }
};