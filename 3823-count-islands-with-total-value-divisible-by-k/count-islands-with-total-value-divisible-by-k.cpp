class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long total_sum = 0;
                    queue<pair<int, int>> q;

                    total_sum += grid[i][j];
                    grid[i][j] = 0; 
                    q.push({i, j});

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (auto& d : dirs) {
                            int nr = r + d[0];
                            int nc = c + d[1];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                total_sum += grid[nr][nc];
                                grid[nr][nc] = 0; 
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (total_sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};