class Solution {
public:
    struct Node {
        long long val;
        int l, r;

        bool operator<(const Node& other) const {
            return val < other.val; // max heap
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        // logs
        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }

        int K = lg[n] + 1;

        vector<vector<int>> stMax(K, vector<int>(n));
        vector<vector<int>> stMin(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            int len = 1 << j;
            int half = len >> 1;

            for (int i = 0; i + len <= n; i++) {
                stMax[j][i] =
                    max(stMax[j - 1][i], stMax[j - 1][i + half]);

                stMin[j][i] =
                    min(stMin[j - 1][i], stMin[j - 1][i + half]);
            }
        }

        auto value = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int p = lg[len];

            int mx = max(stMax[p][l],
                         stMax[p][r - (1 << p) + 1]);

            int mn = min(stMin[p][l],
                         stMin[p][r - (1 << p) + 1]);

            return 1LL * mx - mn;
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            if (cur.r > cur.l) {
                int nr = cur.r - 1;
                pq.push({value(cur.l, nr), cur.l, nr});
            }
        }

        return ans;
    }
};