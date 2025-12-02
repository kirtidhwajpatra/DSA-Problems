 class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    auto dp = std::vector(m, std::vector(n, 0));

    int result = 0;
    for(int row = 0; row < m; ++row) {
      for(int col = 0; col < n; ++col) {
        if(matrix[row][col] == '1') {
          int up = row > 0 ? dp[row - 1][col] : 0;
          int upperLeft = (row > 0 && col > 0) ? dp[row - 1][col - 1] : 0;
          int left = col > 0 ? dp[row][col - 1] : 0;
          dp[row][col] = std::min({up, upperLeft, left}) + 1;     // +1 b/c we are at a '1' square
          result = std::max(result, dp[row][col] * dp[row][col]); // Answer requires area
        }
      }
    }
    return result;
  }
};