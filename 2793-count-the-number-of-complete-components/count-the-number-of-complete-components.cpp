class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                if (isComplete(component, adj)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, component);
            }
        }
    }

    bool isComplete(const vector<int>& component, const vector<vector<int>>& adj) {
        int m = component.size();
        for (int node : component) {

            if (adj[node].size() != m - 1) {
                return false;
            }
        }
        return true;
    }
};