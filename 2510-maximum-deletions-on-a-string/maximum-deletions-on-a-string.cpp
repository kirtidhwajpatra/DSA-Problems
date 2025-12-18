class Solution {
public:

    int deleteString(string s) {
        int n = s.size();

        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j > i; j--) {


                if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }

        vector<int> dp(n + 1, 1);


        for (int i = n - 1; i >= 0; i--) {
            for (int len = 1; i + 2 * len <= n; len++) {
                if (lcp[i][i + len] >= len) {

                    dp[i] = max(dp[i], 1 + dp[i + len]);
                }


            }


          }
        return dp[0];
    }


};
