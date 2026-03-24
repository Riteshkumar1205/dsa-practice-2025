class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        int size = n * m;
        vector<int> res(size, 1);
        
        // Prefix pass
        int prefix = 1;
        for (int i = 0; i < size; i++) {
            res[i] = prefix;
            int r = i / m, c = i % m;
            prefix = (prefix * (grid[r][c] % MOD)) % MOD;
        }
        
        // Suffix pass
        int suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            res[i] = (res[i] * suffix) % MOD;
            int r = i / m, c = i % m;
            suffix = (suffix * (grid[r][c] % MOD)) % MOD;
        }
        
        // Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < size; i++) {
            ans[i / m][i % m] = res[i];
        }
        
        return ans;
    }
};