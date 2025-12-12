class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image; 

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == originalColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
