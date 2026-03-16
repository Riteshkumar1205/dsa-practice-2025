class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // area 0 rhombus
                st.insert(grid[i][j]);

                for(int k = 1; ; k++){
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n) break;

                    int sum = 0;

                    int r = i-k, c = j;

                    // top -> right
                    for(int t=0;t<k;t++){
                        sum += grid[r+t][c+t];
                    }

                    // right -> bottom
                    for(int t=0;t<k;t++){
                        sum += grid[i+t][j+k-t];
                    }

                    // bottom -> left
                    for(int t=0;t<k;t++){
                        sum += grid[i+k-t][j-t];
                    }

                    // left -> top
                    for(int t=0;t<k;t++){
                        sum += grid[i-t][j-k+t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++){
            ans.push_back(*it);
        }

        return ans;
    }
};