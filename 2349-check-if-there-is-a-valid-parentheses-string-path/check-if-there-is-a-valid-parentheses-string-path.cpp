class Solution {
    int m, n;
    bool visited[100][100][105];

    bool dfs(int r, int c, int bal, const std::vector<std::vector<char>>& grid) {
        bal += (grid[r][c] == '(' ? 1 : -1);

        if (bal < 0) return false;

        int remaining = (m - 1 - r) + (n - 1 - c);
        if (bal > remaining) return false;

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (visited[r][c][bal]) return false;
        visited[r][c][bal] = true;

        if (c + 1 < n && dfs(r, c + 1, bal, grid)) return true;
        if (r + 1 < m && dfs(r + 1, c, bal, grid)) return true;

        return false;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        std::memset(visited, 0, sizeof(visited));

        return dfs(0, 0, 0, grid);
    }
};