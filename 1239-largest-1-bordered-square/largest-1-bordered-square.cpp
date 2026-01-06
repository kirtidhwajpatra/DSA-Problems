class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> right(n, vector<int>(m, 0));
        
        vector<vector<int>> down(n, vector<int>(m, 0));
        
           for (int i = n - 1; i >= 0; i--) {



            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = 1 + (j + 1 < m ? right[i][j + 1] : 0);
                    down[i][j]  = 1 + (i + 1 < n ? down[i + 1][j]  : 0);
                }
             }
           }
   

        
        for (int len = min(n, m); len > 0; len--) {

            for (int i = 0; i + len - 1 < n; i++) {

                for (int j = 0; j + len - 1 < m; j++) {
                    if (right[i][j] >= len &&
                        down[i][j] >= len &&
                        right[i + len - 1][j] >= len &&
                        down[i][j + len - 1] >= len) {
                       
                       
                        return len * len;
                    }
                }



            }
           }
        
          return 0;
    
    
      }
};
