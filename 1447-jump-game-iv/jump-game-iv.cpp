class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        // Store all indices for each value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int idx = q.front();
                q.pop();

                // Reached last index
                if (idx == n - 1) return steps;

                // i - 1
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                // i + 1
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // Same value jumps
                for (int nextIdx : mp[arr[idx]]) {
                    if (!vis[nextIdx]) {
                        vis[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }

                // Clear to prevent reprocessing
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};