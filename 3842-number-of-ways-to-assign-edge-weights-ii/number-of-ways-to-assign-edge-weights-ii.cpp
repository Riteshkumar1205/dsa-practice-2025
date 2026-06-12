#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    // Precompute powers of 2 modulo 10^9 + 7
    vector<long long> power2;
    void precomputePowers(int max_len) {
        power2.resize(max_len + 1);
        power2[0] = 1;
        for (int i = 1; i <= max_len; ++i) {
            power2[i] = (power2[i - 1] * 2) % MOD;
        }
    }

    // DFS to initialize depths and the first ancestor (up[v][0])
    void dfs(int node, int parent, int d) {
        depth[node] = d;
        up[node][0] = parent;
        for (int i = 1; i < LOG; ++i) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1);
            }
        }
    }

    // Function to find the LCA of two nodes
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // Lift u to the same depth as v
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        // Lift both u and v together until they are just below their LCA
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        
        adj.assign(n + 1, vector<int>());
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        
        precomputePowers(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Root the tree at node 1
        dfs(1, -1, 0);
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            
            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];
            
            // Formula: 2^(L - 1) % MOD
            answer.push_back(power2[pathLength - 1]);
        }
        
        return answer;
    }
};