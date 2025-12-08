class Solution {
public:
    int m, n;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>& grid, int x, int y) {
        int gold = grid[x][y];
        int best = 0;

        grid[x][y] = 0; 

        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                best = max(best, dfs(grid, nx, ny));
            }
        }

        grid[x][y] = gold; 
        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
