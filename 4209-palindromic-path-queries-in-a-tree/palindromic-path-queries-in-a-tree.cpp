class FenwickTree {
    int n;
    vector<int> tree;
public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) {
            tree[i] ^= delta;
        }
    }

    // Range update: XOR with val on [l, r]
    void rangeUpdate(int l, int r, int val) {
        update(l, val);
        update(r + 1, val);
    }

    // Point query: prefix XOR up to i
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res ^= tree[i];
        }
        return res;
    }
};

class Solution {
    int timer = 0;
    int LOG = 17;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;

    void dfs(int u, int p, int d) {
        tin[u] = ++timer;
        up[u][0] = p;
        depth[u] = d;
        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = timer;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));
        timer = 0;

        dfs(0, 0, 0);

        FenwickTree bit(n);
        vector<int> current_char(n);

        // Initialize characters and range updates
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            current_char[i] = mask;
            bit.rangeUpdate(tin[i], tout[i], mask);
        }

        vector<bool> ans;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u;
                char c;
                stringstream ss(q);
                string type;
                ss >> type >> u >> c;

                int old_mask = current_char[u];
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;

                current_char[u] = new_mask;
                bit.rangeUpdate(tin[u], tout[u], diff);
            } else {
                int u, v;
                stringstream ss(q);
                string type;
                ss >> type >> u >> v;

                int lca = getLCA(u, v);
                int mask_u = bit.query(tin[u]);
                int mask_v = bit.query(tin[v]);
                int mask_lca_node = current_char[lca];

                int path_mask = mask_u ^ mask_v ^ mask_lca_node;

                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};