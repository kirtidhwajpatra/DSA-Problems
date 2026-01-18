class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> memo(n, vector<int>(m, 0));

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, dfs(matrix, memo, i, j));
            }
        }
        return answer;
    }

private:
    int dfs(vector<vector<int>>& mat, vector<vector<int>>& memo, int r, int c) {
        if (memo[r][c]) return memo[r][c];

        static int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int best = 1;



        for (auto& d : dirs) {


            int nr = r + d[0], nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nr < mat.size() && nc < mat[0].size()
                && mat[nr][nc] > mat[r][c]) {
                best = max(best, 1 + dfs(mat, memo, nr, nc));


            }
        }



        return memo[r][c] = best;



    }
};
