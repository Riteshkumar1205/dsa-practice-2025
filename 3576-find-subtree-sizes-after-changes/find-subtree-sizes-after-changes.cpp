class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        // First DFS: Reassign parents to the closest matching character ancestor
        auto reassign = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_ancestor = last_seen[char_idx];
            
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            last_seen[char_idx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            last_seen[char_idx] = prev_ancestor; // Backtrack
        };

        reassign(reassign, 0);

        // Build the modified tree
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        // Second DFS: Calculate subtree sizes in the final tree
        vector<int> ans(n, 1);
        auto count_sizes = [&](auto& self, int u) -> void {
            for (int v : new_adj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        count_sizes(count_sizes, 0);
        return ans;
    }
};