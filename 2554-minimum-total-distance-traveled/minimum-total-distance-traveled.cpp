class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size(), m = factory.size();
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

        // Base case: no robots left → 0 cost
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        for (int j = m - 1; j >= 0; j--) {
            int pos = factory[j][0];
            int limit = factory[j][1];

            for (int i = n; i >= 0; i--) {
                long long cost = 0;

                // Try assigning k robots to this factory
                for (int k = 0; k <= limit && i + k <= n; k++) {
                    if (k > 0) {
                        cost += abs(robot[i + k - 1] - pos);
                    }

                    dp[i][j] = min(dp[i][j], cost + dp[i + k][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};