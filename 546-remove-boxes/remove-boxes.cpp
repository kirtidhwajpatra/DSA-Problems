class Solution {
public:
    int dp[105][105][105];

    int solve(int l, int r, int k, vector<int>& b) {


          if (l > r) return 0;
           if (dp[l][r][k]) return dp[l][r][k];

        int res = (k + 1) * (k + 1) + solve(l + 1, r, 0, b);




        for (int i = l + 1; i <= r; i++) {
            if (b[i] == b[l]) {
                res = max(
                    res,
                    solve(l + 1, i - 1, 0, b) + solve(i, r, k + 1, b)
                );
              }

        }

            return dp[l][r][k] = res;
    }

    int removeBoxes(vector<int>& boxes) {


        memset(dp, 0, sizeof(dp));
        return solve(0, boxes.size() - 1, 0, boxes);
          }
};
