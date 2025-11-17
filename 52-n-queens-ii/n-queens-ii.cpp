class Solution {
public:
    int total = 0;
    void backtrack(int n, int row, vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            total++;
            
            return;
        }
        for (int c = 0; c < n; c++) {

            if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;
            backtrack(n, row + 1, col, diag1, diag2);
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }
    int totalNQueens(int n) {

        vector<int> col(n), diag1(2*n), diag2(2*n);
        backtrack(n, 0, col, diag1, diag2);
        return total;

    }
};
