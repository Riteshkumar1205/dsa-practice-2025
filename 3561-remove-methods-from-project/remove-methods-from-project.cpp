#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 1: Find all suspicious methods reachable from k using BFS
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                canRemove = false;
                break;
            }
        }

        // Step 3: Build the result
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!canRemove || !suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};