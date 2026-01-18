class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int ans = 1;

        static int row[51][52], col[52][51], d1[52][52], d2[52][52];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + g[i][j];
                col[i + 1][j] = col[i][j] + g[i][j];
                d1[i + 1][j + 1] = d1[i][j] + g[i][j];
                d2[i + 1][j] = d2[i][j + 1] + g[i][j];
            }
        }

        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int sum = row[i][j + k] - row[i][j];

                    if (d1[i + k][j + k] - d1[i][j] != sum) continue;
                    if (d2[i + k][j] - d2[i][j + k] != sum) continue;

                    bool ok = true;

                    for (int t = 0; t < k && ok; t++) {
                        if (row[i + t][j + k] - row[i + t][j] != sum ||
                            col[i + k][j + t] - col[i][j + t] != sum) {
                            ok = false;
                        }
                    }

                    if (ok) ans = k;
                }
            }
        }
        return ans;
    }
};
