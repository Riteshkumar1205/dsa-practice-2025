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

        // ---- Rolling Hash ----
        vector<long long> powB(n + 1), hS(n + 1), hT(n + 1);
        powB[0] = 1;
        for (int i = 0; i < n; i++) {
            powB[i + 1] = powB[i] * BASE % MOD;
            hS[i + 1] = (hS[i] * BASE + source[i]) % MOD;
            hT[i + 1] = (hT[i] * BASE + target[i]) % MOD;
        }

        auto getHash = [&](vector<long long>& h, int l, int r) {
            return (h[r] - h[l] * powB[r - l] % MOD + MOD) % MOD;
        };

        // ---- Group strings by length ----
        unordered_map<long long, int> id;
        map<int, vector<long long>> byLen;
        int idx = 0;

        auto encode = [&](const string& s) {
            long long h = 0;
            for (char c : s) h = (h * BASE + c) % MOD;
            return (h << 11) | s.size();
        };

        for (int i = 0; i < original.size(); i++) {
            long long a = encode(original[i]);
            long long b = encode(changed[i]);
            if (!id.count(a)) id[a] = idx++, byLen[original[i].size()].push_back(a);
            if (!id.count(b)) id[b] = idx++, byLen[changed[i].size()].push_back(b);
        }

        // ---- Build per-length graphs ----
        unordered_map<int, vector<vector<long long>>> dist;
        unordered_map<int, unordered_map<long long,int>> localId;

        for (auto& [len, vec] : byLen) {
            int m = vec.size();
            dist[len].assign(m, vector<long long>(m, INF));
            for (int i = 0; i < m; i++) {
                localId[len][vec[i]] = i;
                dist[len][i][i] = 0;
            }
        }

        for (int i = 0; i < original.size(); i++) {
            int len = original[i].size();
            long long a = encode(original[i]);
            long long b = encode(changed[i]);
            int u = localId[len][a];
            int v = localId[len][b];
            dist[len][u][v] = min(dist[len][u][v], (long long)cost[i]);
        }

        // ---- Floyd–Warshall per length ----
        for (auto& [len, d] : dist) {
            int m = d.size();
            for (int k = 0; k < m; k++)
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < m; j++)
                        if (d[i][k] < INF && d[k][j] < INF)
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }

        // ---- DP ----
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (auto& [len, vec] : byLen) {
                if (i + len > n) continue;

                long long hs = (getHash(hS, i, i + len) << 11) | len;
                long long ht = (getHash(hT, i, i + len) << 11) | len;

                if (!localId[len].count(hs) || !localId[len].count(ht))
                    continue;

                long long c = dist[len][localId[len][hs]][localId[len][ht]];
                if (c < INF)
                    dp[i] = min(dp[i], c + dp[i + len]);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
