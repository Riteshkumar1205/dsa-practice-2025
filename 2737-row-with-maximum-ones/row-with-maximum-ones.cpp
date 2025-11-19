class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int rowIndex = 0;

        for (int i = 0; i < mat.size(); ++i) {
            int ones = count(mat[i].begin(), mat[i].end(), 1);
            if (ones > maxOnes) {
                maxOnes = ones;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};
