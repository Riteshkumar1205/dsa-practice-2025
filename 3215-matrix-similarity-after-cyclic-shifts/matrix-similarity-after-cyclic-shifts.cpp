class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k%n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int newIndex;

              if(i % 2 == 0){
                //even row -> left shift
                newIndex = (j + shift) % n;
              }
              else {
                newIndex = (j - shift + n) % n;
              }
              if(mat[i][j] != mat[i][newIndex]){
                return false;
              }
            }
        }
        return true;
    }
};