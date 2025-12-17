class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int k = min(m - 1, n - 1);     
        int total = m + n - 2;

        for (int i = 1; i <= k; i++) {
            res = res * (total - k + i) / i;
        }

        return (int)res;
    }
};
