class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Total sum
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }
        
        // If odd, cannot split equally
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        
        // Check horizontal cuts
        long long prefix = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                prefix += grid[i][j];
            }
            if (prefix == target) return true;
        }
        
        // Check vertical cuts
        vector<long long> colSum(n, 0);
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        
        prefix = 0;
        for (int j = 0; j < n - 1; j++) {
            prefix += colSum[j];
            if (prefix == target) return true;
        }
        
        return false;
    }
};