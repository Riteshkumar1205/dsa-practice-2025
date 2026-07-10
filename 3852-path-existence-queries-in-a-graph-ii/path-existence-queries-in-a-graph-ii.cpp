#include <vector>
#include <algorithm>
#include <bit> // for std::bit_width

using namespace std;

class Solution {
    // Moved to private members or local vectors
    vector<vector<int>> up;
    vector<int> pos;

public:
    int cnt(int u, int v, int maxL) {
        if (u == v) return 0;
        if (up[0][u] >= v) return 1;
        // Check if v is even reachable
        if (up[maxL - 1][u] < v) return -1;

        int step = 0;
        for (int j = maxL - 1; j >= 0; j--) {
            if (up[j][u] < v) {
                step += (1 << j);
                u = up[j][u];
            }
        }
        return step + 1;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int maxL = bit_width((unsigned)n) + 1;
        
        // Initialize structures fresh for every test case
        up.assign(maxL, vector<int>(n));
        pos.resize(n);
        vector<pair<int, int>> xId(n);
        
        for (int i = 0; i < n; i++) xId[i] = {nums[i], i};
        sort(xId.begin(), xId.end());
        
        for (int i = 0; i < n; i++) pos[xId[i].second] = i;
        
        // Sliding window
        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n && xId[r + 1].first - xId[l].first <= maxDiff) r++;
            up[0][l] = r;
        }

        // Compute binary lifting tables
        for (int j = 1; j < maxL; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            auto [u, v] = minmax(pos[q[0]], pos[q[1]]);
            ans.push_back(cnt(u, v, maxL));
        }
        return ans;
    }
};