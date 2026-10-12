class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        vector<int> count(31, 0);

        for (int x : nums) {
            for (int b = 0; b < 31; ++b) {
                if ((x >> b) & 1) {
                    count[b]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; ++i) {
            long long cur = 0;
            for (int b = 0; b < 31; ++b) {
                if (count[b] > 0) {
                    cur |= (1LL << b);
                    count[b]--;
                }
            }
            ans = (ans + (cur % mod) * (cur % mod)) % mod;
        }

        return ans;
    }
};