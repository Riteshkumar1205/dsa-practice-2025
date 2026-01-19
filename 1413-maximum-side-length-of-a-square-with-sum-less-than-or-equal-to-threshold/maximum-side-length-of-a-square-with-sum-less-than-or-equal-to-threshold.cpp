class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int k = ans + 1;
                if (i >= k && j >= k) {
                    int sum = pre[i][j]
                            - pre[i - k][j]
                            - pre[i][j - k]
                            + pre[i - k][j - k];
                    if (sum <= threshold) {
                        ans = k;
                    }
                }
            }
        }
        
        return ans;
    }
};
