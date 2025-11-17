class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& b, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || b[i][j] != 'O') return;

        b[i][j] = '#';
        
        dfs(b, i+1, j);
        dfs(b, i-1, j);
        dfs(b, i, j+1);
        dfs(b, i, j-1);
    }
    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {

            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        for (int j = 0; j < n; j++) {

            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';

            }
        }
    }
};
