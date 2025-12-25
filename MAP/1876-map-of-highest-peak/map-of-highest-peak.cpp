class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> h(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(isWater[i][j]) h[i][j] = 0, q.push({i,j});
        
        vector<pair<int,int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for(auto [dr,dc]: dirs) {
                int nr = r + dr, nc = c + dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && h[nr][nc]==-1)
                    h[nr][nc] = h[r][c]+1, q.push({nr,nc});
            }
        }
        return h;
    }
};
