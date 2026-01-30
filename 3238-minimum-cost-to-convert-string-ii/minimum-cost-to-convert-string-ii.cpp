class Solution {
public:
    static constexpr long long INF = 1e18;
    static constexpr long long MOD = 1000000007;
    static constexpr long long BASE = 91138233;

    long long minimumCost(string source, string target,
                           vector<string>& original,
                           vector<string>& changed,
                           vector<int>& cost) {
        int n = source.size();

        vector<long long> powB(n + 1), hS(n + 1), hT(n + 1);
        powB[0] = 1;
        for (int i = 0; i < n; i++) {
            powB[i + 1] = (powB[i] * BASE) % MOD;
            hS[i + 1] = (hS[i] * BASE + source[i]) % MOD;
            hT[i + 1] = (hT[i] * BASE + target[i]) % MOD;
        }

        auto getHash = [&](vector<long long>& h, int l, int r) {
            return (h[r] - h[l] * powB[r - l] % MOD + MOD) % MOD;
        };

        unordered_map<long long, int> id;
        vector<int> lens;
        int idx = 0;

        auto encode = [&](const string& s) {
            long long h = 0;
            for (char c : s) h = (h * BASE + c) % MOD;
            return (h << 11) | s.size();
        };

        for (auto& s : original) {
            long long key = encode(s);
            if (!id.count(key)) {
                id[key] = idx++;
                lens.push_back(s.size());
            }
        }
        for (auto& s : changed) {
            long long key = encode(s);
            if (!id.count(key))
                id[key] = idx++;
        }

        vector<vector<long long>> dist(idx, vector<long long>(idx, INF));
        for (int i = 0; i < idx; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            dist[id[encode(original[i])]][id[encode(changed[i])]]
                = min(dist[id[encode(original[i])]][id[encode(changed[i])]],
                      (long long)cost[i]);
        }

        for (int k = 0; k < idx; k++)
            for (int i = 0; i < idx; i++)
                for (int j = 0; j < idx; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (int len : lens) {
                if (i + len > n) continue;

                long long hs = getHash(hS, i, i + len);
                long long ht = getHash(hT, i, i + len);
                long long ks = (hs << 11) | len;
                long long kt = (ht << 11) | len;

                if (!id.count(ks) || !id.count(kt)) continue;

                long long c = dist[id[ks]][id[kt]];
                if (c < INF)
                    dp[i] = min(dp[i], c + dp[i + len]);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
