class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        auto find = [&](auto self, int i) -> int {
            if (parent[i] == i)
                return i;
            return parent[i] = self(self, parent[i]);
        };

        auto unite = [&](int i, int j) {
            int root_i = find(find, i);
            int root_j = find(find, j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
            }
        };

        for (int i = 0; i < n - 1; ++i) {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                unite(i, i + 1);
            }
        }

        vector<bool> result;
        for (const auto& q : queries) {
            result.push_back(find(find, q[0]) == find(find, q[1]));
        }

        return result;
    }
};