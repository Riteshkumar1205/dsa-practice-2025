class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int mod_val = num % k;

            next_dp[mod_val]++;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * mod_val) % k] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return ans;
    }
};