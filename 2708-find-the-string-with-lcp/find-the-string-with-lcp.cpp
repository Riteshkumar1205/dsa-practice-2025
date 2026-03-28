class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 1: Check diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        // DSU
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[a] = b;
        };

        // Step 2: Union where lcp > 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 3: Assign characters
        unordered_map<int, char> mp;
        char ch = 'a';

        string res(n, '?');

        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (!mp.count(p)) {
                if (ch > 'z') return ""; // too many groups
                mp[p] = ch++;
            }
            res[i] = mp[p];
        }

        // Step 4: Validate LCP
        vector<vector<int>> check(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i] == res[j]) {
                    if (i + 1 < n && j + 1 < n)
                        check[i][j] = 1 + check[i + 1][j + 1];
                    else
                        check[i][j] = 1;
                } else {
                    check[i][j] = 0;
                }
            }
        }

        if (check != lcp) return "";

        return res;
    }
};