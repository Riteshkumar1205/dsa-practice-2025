class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> tree_sum;
    vector<long long> tree_sq;
    vector<long long> lazy;

    void push_down(int node, int start, int end) {
        if (lazy[node] == 0) return;
        int mid = start + (end - start) / 2;
        int left_len = mid - start + 1;
        int right_len = end - mid;
        long long val = lazy[node];

        tree_sq[2 * node] = (tree_sq[2 * node] + 2 * val * tree_sum[2 * node] + val * val % MOD * left_len) % MOD;
        tree_sum[2 * node] = (tree_sum[2 * node] + val * left_len) % MOD;
        lazy[2 * node] = (lazy[2 * node] + val) % MOD;

        tree_sq[2 * node + 1] = (tree_sq[2 * node + 1] + 2 * val * tree_sum[2 * node + 1] + val * val % MOD * right_len) % MOD;
        tree_sum[2 * node + 1] = (tree_sum[2 * node + 1] + val * right_len) % MOD;
        lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            int len = end - start + 1;
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] + val * val % MOD * len) % MOD;
            tree_sum[node] = (tree_sum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_pos;
        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] + 1 : 0;
            update(1, 0, n - 1, prev, i, 1);
            total_ans = (total_ans + tree_sq[1]) % MOD;
            last_pos[nums[i]] = i;
        }

        return (total_ans % MOD + MOD) % MOD;
    }
};