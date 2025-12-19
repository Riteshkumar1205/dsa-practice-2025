class Solution {
public:
    int count = 0;
    vector<bool> col, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            backtrack(row + 1, n);
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

    int totalNQueens(int n) {
        col.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);

        backtrack(0, n);
        return count;
    }
};
