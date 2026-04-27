class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();


        vector<vector<vector<int>>> dirs = {
            {},                             
            {{0,1},{0,-1}},                 
            {{1,0},{-1,0}},             
            {{0,-1},{1,0}},                
            {{0,1},{1,0}},                 
            {{0,-1},{-1,0}},               
            {{0,1},{-1,0}}                 
        };


        map<pair<int,int>, pair<int,int>> opposite = {
            {{0,1},{0,-1}},
            {{0,-1},{0,1}},
            {{1,0},{-1,0}},
            {{-1,0},{1,0}}
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) return true;

            for(auto &d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny]) continue;


                auto back = opposite[{d[0], d[1]}];
                for(auto &nd : dirs[grid[nx][ny]]) {
                    if(nd[0] == back.first && nd[1] == back.second) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }
        return false;
    }
};