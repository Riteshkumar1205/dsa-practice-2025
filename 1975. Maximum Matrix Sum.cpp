class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                totalSum += llabs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};
