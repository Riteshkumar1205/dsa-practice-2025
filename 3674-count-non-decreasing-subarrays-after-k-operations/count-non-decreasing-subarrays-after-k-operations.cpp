class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long ans = 0;
        long long ops = 0;
        deque<int> dq;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int idx = dq.front();
                dq.pop_front();
                int next_idx = dq.empty() ? r + 1 : dq.front();
                ops += 1LL * (next_idx - idx) * (nums[l] - nums[idx]);
            }
            dq.push_front(l);

            while (r >= l && ops > k) {
                int max_idx = dq.back();
                ops -= (nums[max_idx] - nums[r]);
                if (max_idx == r) {
                    dq.pop_back();
                }
                --r;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};