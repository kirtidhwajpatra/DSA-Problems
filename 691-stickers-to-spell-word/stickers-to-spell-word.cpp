class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        int full = (1 << m) - 1;
        vector<int> dp(1 << m, -1);
        dp[0] = 0;

        vector<vector<int>> cnt(stickers.size(), vector<int>(26));
        for (int i = 0; i < stickers.size(); i++) {
            for (char c : stickers[i]) cnt[i][c - 'a']++;
        }

        for (int mask = 0; mask <= full; mask++) {


            if (dp[mask] == -1) continue;
            for (int i = 0; i < stickers.size(); i++) {
                int next = mask;

                vector<int> c = cnt[i];
                for (int j = 0; j < m; j++) {
                    if ((next >> j) & 1) continue;
                    if (c[target[j] - 'a'] > 0) {
                        c[target[j] - 'a']--;
                        next |= (1 << j);
                    }
                }

                if (dp[next] == -1 || dp[next] > dp[mask] + 1) {
                    dp[next] = dp[mask] + 1;
                }
                
            }


        }

        return dp[full];
    }
};
